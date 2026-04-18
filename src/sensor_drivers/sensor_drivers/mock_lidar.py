#!/usr/bin/env python3

import math
from typing import List, Optional, Tuple

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data

from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan


Point = Tuple[float, float]
Segment = Tuple[Point, Point]


class MockLidarNode(Node):
    def __init__(self) -> None:
        super().__init__('mock_lidar')

        # ---- Parameters ----
        self.declare_parameter('scan_topic', '/sensors/lidar/scan')
        self.declare_parameter('odom_topic', '/odometry/filtered')
        self.declare_parameter('frame_id', 'lidar_link')
        self.declare_parameter('publish_rate_hz', 10.0)

        self.declare_parameter('angle_min', -math.pi)
        self.declare_parameter('angle_max', math.pi)
        self.declare_parameter('num_beams', 360)

        self.declare_parameter('range_min', 0.12)
        self.declare_parameter('range_max', 12.0)

        # Simple synthetic world in odom frame
        # Big room + a few obstacles to make SLAM non-degenerate.
        self.declare_parameter('room_min_x', -8.0)
        self.declare_parameter('room_max_x', 8.0)
        self.declare_parameter('room_min_y', -6.0)
        self.declare_parameter('room_max_y', 6.0)

        self.scan_topic = self.get_parameter('scan_topic').value
        self.odom_topic = self.get_parameter('odom_topic').value
        self.frame_id = self.get_parameter('frame_id').value
        self.publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)

        self.angle_min = float(self.get_parameter('angle_min').value)
        self.angle_max = float(self.get_parameter('angle_max').value)
        self.num_beams = int(self.get_parameter('num_beams').value)

        self.range_min = float(self.get_parameter('range_min').value)
        self.range_max = float(self.get_parameter('range_max').value)

        room_min_x = float(self.get_parameter('room_min_x').value)
        room_max_x = float(self.get_parameter('room_max_x').value)
        room_min_y = float(self.get_parameter('room_min_y').value)
        room_max_y = float(self.get_parameter('room_max_y').value)

        self.angle_increment = (self.angle_max - self.angle_min) / float(self.num_beams)

        # Robot pose in odom frame
        self.robot_x: float = 0.0
        self.robot_y: float = 0.0
        self.robot_yaw: float = 0.0
        self.pose_ready: bool = False

        # Fixed world geometry in odom frame
        self.segments: List[Segment] = []
        self._add_room(room_min_x, room_max_x, room_min_y, room_max_y)

        # Add a few asymmetric obstacles so slam_toolbox has landmarks/features.
        self._add_box(2.0, 3.2, 1.0, 2.5)
        self._add_box(-4.5, -3.2, -2.8, -1.2)
        self._add_box(0.5, 1.1, -4.5, -3.0)
        self._add_box(-1.5, 0.0, 3.0, 4.8)

        self.scan_pub = self.create_publisher(
            LaserScan,
            self.scan_topic,
            qos_profile_sensor_data
        )

        self.odom_sub = self.create_subscription(
            Odometry,
            self.odom_topic,
            self.odom_callback,
            qos_profile_sensor_data
        )

        period = 1.0 / self.publish_rate_hz
        self.timer = self.create_timer(period, self.publish_scan)

        self.get_logger().info(
            f'mock_lidar started: scan_topic={self.scan_topic}, '
            f'odom_topic={self.odom_topic}, frame_id={self.frame_id}'
        )

    def _add_room(self, min_x: float, max_x: float, min_y: float, max_y: float) -> None:
        p1 = (min_x, min_y)
        p2 = (max_x, min_y)
        p3 = (max_x, max_y)
        p4 = (min_x, max_y)

        self.segments.extend([
            (p1, p2),
            (p2, p3),
            (p3, p4),
            (p4, p1),
        ])

    def _add_box(self, min_x: float, max_x: float, min_y: float, max_y: float) -> None:
        p1 = (min_x, min_y)
        p2 = (max_x, min_y)
        p3 = (max_x, max_y)
        p4 = (min_x, max_y)

        self.segments.extend([
            (p1, p2),
            (p2, p3),
            (p3, p4),
            (p4, p1),
        ])

    def odom_callback(self, msg: Odometry) -> None:
        self.robot_x = msg.pose.pose.position.x
        self.robot_y = msg.pose.pose.position.y

        q = msg.pose.pose.orientation
        self.robot_yaw = self.quaternion_to_yaw(q.x, q.y, q.z, q.w)
        self.pose_ready = True

    @staticmethod
    def quaternion_to_yaw(x: float, y: float, z: float, w: float) -> float:
        siny_cosp = 2.0 * (w * z + x * y)
        cosy_cosp = 1.0 - 2.0 * (y * y + z * z)
        return math.atan2(siny_cosp, cosy_cosp)

    @staticmethod
    def cross(ax: float, ay: float, bx: float, by: float) -> float:
        return ax * by - ay * bx

    def ray_segment_intersection(
        self,
        ray_origin: Point,
        ray_dir: Point,
        seg_a: Point,
        seg_b: Point
    ) -> Optional[float]:
        """
        Returns distance t along the ray origin + t * ray_dir, or None if no hit.
        ray_dir must be unit or near-unit length.
        """
        ox, oy = ray_origin
        dx, dy = ray_dir

        ax, ay = seg_a
        bx, by = seg_b

        sx = bx - ax
        sy = by - ay

        denom = self.cross(dx, dy, sx, sy)
        if abs(denom) < 1e-9:
            return None

        qpx = ax - ox
        qpy = ay - oy

        t = self.cross(qpx, qpy, sx, sy) / denom
        u = self.cross(qpx, qpy, dx, dy) / denom

        if t >= 0.0 and 0.0 <= u <= 1.0:
            return t
        return None

    def cast_ray(self, origin_x: float, origin_y: float, angle_world: float) -> float:
        dx = math.cos(angle_world)
        dy = math.sin(angle_world)

        min_dist = self.range_max

        for seg_a, seg_b in self.segments:
            hit = self.ray_segment_intersection(
                (origin_x, origin_y),
                (dx, dy),
                seg_a,
                seg_b
            )
            if hit is not None and self.range_min <= hit <= min_dist:
                min_dist = hit

        return min_dist

    def publish_scan(self) -> None:
        if not self.pose_ready:
            return

        msg = LaserScan()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self.frame_id

        msg.angle_min = float(self.angle_min)
        msg.angle_max = float(self.angle_max)
        msg.angle_increment = float(self.angle_increment)

        msg.time_increment = 0.0
        msg.scan_time = 1.0 / self.publish_rate_hz

        msg.range_min = float(self.range_min)
        msg.range_max = float(self.range_max)

        ranges: List[float] = []

        # LaserScan angles are in lidar frame. Convert to world using robot yaw.
        for i in range(self.num_beams):
            angle_lidar = self.angle_min + i * self.angle_increment
            angle_world = self.robot_yaw + angle_lidar

            r = self.cast_ray(self.robot_x, self.robot_y, angle_world)
            ranges.append(float(r))

        msg.ranges = ranges
        msg.intensities = [100.0] * self.num_beams

        self.scan_pub.publish(msg)


def main(args=None) -> None:
    rclpy.init(args=args)
    node = MockLidarNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()