#!/usr/bin/env python3

import math

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Point
from autonomy_msgs.msg import Detection, DetectionArray
from visualization_msgs.msg import Marker, MarkerArray


class LidarPerceptionNode(Node):
    def __init__(self):
        super().__init__('lidar_perception_node')

        self.scan_sub = self.create_subscription(
            LaserScan,
            '/sensors/lidar/scan',
            self.scan_callback,
            10
        )

        self.detections_pub = self.create_publisher(
            DetectionArray,
            '/perception/lidar/detections',
            10
        )

        self.markers_pub = self.create_publisher(
            MarkerArray,
            '/perception/lidar/debug_markers',
            10
        )

        self.declare_parameter('min_x', 0.0)
        self.declare_parameter('max_x', 5.0)
        self.declare_parameter('max_abs_y', 2.0)
        self.declare_parameter('min_range_threshold', 0.05)

        self.declare_parameter('cluster_distance_threshold', 0.35)
        self.declare_parameter('min_cluster_size', 3)

        self.declare_parameter('min_detection_distance', 0.2)
        self.declare_parameter('max_detection_distance', 5.0)
        self.declare_parameter('max_cluster_size_x', 0.8)
        self.declare_parameter('max_cluster_size_y', 0.8)

        self.min_x = self.get_parameter('min_x').value
        self.max_x = self.get_parameter('max_x').value
        self.max_abs_y = self.get_parameter('max_abs_y').value
        self.min_range_threshold = self.get_parameter('min_range_threshold').value

        self.cluster_distance_threshold = self.get_parameter('cluster_distance_threshold').value
        self.min_cluster_size = self.get_parameter('min_cluster_size').value

        self.min_detection_distance = self.get_parameter('min_detection_distance').value
        self.max_detection_distance = self.get_parameter('max_detection_distance').value
        self.max_cluster_size_x = self.get_parameter('max_cluster_size_x').value
        self.max_cluster_size_y = self.get_parameter('max_cluster_size_y').value

        self.get_logger().info(
            'LiDAR perception node started with params: '
            f'min_x={self.min_x}, max_x={self.max_x}, max_abs_y={self.max_abs_y}, '
            f'cluster_distance_threshold={self.cluster_distance_threshold}, '
            f'min_cluster_size={self.min_cluster_size}, '
            f'max_cluster_size_x={self.max_cluster_size_x}, '
            f'max_cluster_size_y={self.max_cluster_size_y}'
        )



    def scan_callback(self, msg: LaserScan):
        xy_points = self.scan_to_xy(msg)
        roi_points = self.filter_roi(xy_points)
        clusters = self.cluster_points(roi_points)
        detections = self.build_detections(clusters)

        detections_msg = DetectionArray()
        detections_msg.header = msg.header
        detections_msg.header.frame_id = msg.header.frame_id
        detections_msg.detections = detections
        self.detections_pub.publish(detections_msg)

        marker_array = self.build_detection_markers(detections, msg.header)
        self.markers_pub.publish(marker_array)

        self.get_logger().info(
            f'Scan points: raw={len(msg.ranges)}, valid_xy={len(xy_points)}, '
            f'roi={len(roi_points)}, clusters={len(clusters)}, detections={len(detections)}'
        )

    def scan_to_xy(self, scan_msg: LaserScan):
        points = []
        angle = scan_msg.angle_min

        for r in scan_msg.ranges:
            if not math.isfinite(r):
                angle += scan_msg.angle_increment
                continue

            if r < self.min_range_threshold:
                angle += scan_msg.angle_increment
                continue

            if r < scan_msg.range_min or r > scan_msg.range_max:
                angle += scan_msg.angle_increment
                continue

            x = r * math.cos(angle)
            y = r * math.sin(angle)
            points.append((x, y))

            angle += scan_msg.angle_increment

        return points

    def filter_roi(self, points):
        roi = []

        for x, y in points:
            if self.min_x < x < self.max_x and abs(y) < self.max_abs_y:
                roi.append((x, y))

        return roi

    def cluster_points(self, points):
        if not points:
            return []

        clusters = []
        current_cluster = [points[0]]

        for i in range(1, len(points)):
            prev_x, prev_y = points[i - 1]
            curr_x, curr_y = points[i]

            distance = math.hypot(curr_x - prev_x, curr_y - prev_y)

            if distance <= self.cluster_distance_threshold:
                current_cluster.append(points[i])
            else:
                if len(current_cluster) >= self.min_cluster_size:
                    clusters.append(current_cluster)
                current_cluster = [points[i]]

        if len(current_cluster) >= self.min_cluster_size:
            clusters.append(current_cluster)

        return clusters

    def build_detections(self, clusters):
        detections = []

        for cluster in clusters:
            xs = [p[0] for p in cluster]
            ys = [p[1] for p in cluster]

            centroid_x = sum(xs) / len(xs)
            centroid_y = sum(ys) / len(ys)

            size_x = max(xs) - min(xs)
            size_y = max(ys) - min(ys)

            distance = math.hypot(centroid_x, centroid_y)
            angle = math.atan2(centroid_y, centroid_x)

            if distance < self.min_detection_distance:
                continue

            if distance > self.max_detection_distance:
                continue

            if size_x > self.max_cluster_size_x:
                continue

            if size_y > self.max_cluster_size_y:
                continue

            detection = Detection()
            detection.position = Point(
                x=float(centroid_x),
                y=float(centroid_y),
                z=0.0
            )
            detection.distance = float(distance)
            detection.angle = float(angle)
            detection.size_x = float(size_x)
            detection.size_y = float(size_y)
            detection.label = 'obstacle_candidate'
            detection.confidence = 0.6

            detections.append(detection)

        return detections

    def build_detection_markers(self, detections, header):
        marker_array = MarkerArray()

        delete_all_marker = Marker()
        delete_all_marker.header = header
        delete_all_marker.ns = 'lidar_detections'
        delete_all_marker.id = 0
        delete_all_marker.action = Marker.DELETEALL
        marker_array.markers.append(delete_all_marker)

        for i, detection in enumerate(detections):
            marker = Marker()
            marker.header = header
            marker.ns = 'lidar_detections'
            marker.id = i + 1
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD

            marker.pose.position.x = detection.position.x
            marker.pose.position.y = detection.position.y
            marker.pose.position.z = 0.2
            marker.pose.orientation.w = 1.0

            marker.scale.x = max(detection.size_x, 0.2)
            marker.scale.y = max(detection.size_y, 0.2)
            marker.scale.z = 0.2

            marker.color.a = 1.0
            marker.color.r = 1.0
            marker.color.g = 0.0
            marker.color.b = 0.0

            marker_array.markers.append(marker)

        return marker_array


def main(args=None):
    rclpy.init(args=args)
    node = LidarPerceptionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()