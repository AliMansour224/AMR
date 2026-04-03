#!/usr/bin/env python3

import math

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Vector3
from std_msgs.msg import Bool


class PerceptionNode(Node):
    def __init__(self):
        super().__init__('perception_node')

        self.scan_sub = self.create_subscription(
            LaserScan,
            '/sensors/lidar/scan',
            self.scan_callback,
            10
        )

        self.distances_pub = self.create_publisher(
            Vector3,
            '/perception/distances',
            10
        )

        self.obstacle_pub = self.create_publisher(
            Bool,
            '/perception/obstacle_ahead',
            10
        )

        self.obstacle_threshold = 1.0
        self.min_valid_distance = 0.15

        self.get_logger().info('Perception node started.')

    def clean_ranges(self, msg: LaserScan):
        cleaned = []
        for r in msg.ranges:
            if not math.isfinite(r):
                cleaned.append(float('inf'))
            elif r < self.min_valid_distance:
                cleaned.append(float('inf'))
            elif r < msg.range_min or r > msg.range_max:
                cleaned.append(float('inf'))
            else:
                cleaned.append(r)
        return cleaned

    def min_in_sector_by_angle(self, ranges, msg: LaserScan, angle_start, angle_end):
        sector_values = []

        for i, r in enumerate(ranges):
            angle = msg.angle_min + i * msg.angle_increment
            if angle_start <= angle <= angle_end:
                sector_values.append(r)

        if not sector_values:
            return float('inf')

        return min(sector_values)

    def scan_callback(self, msg: LaserScan):
        ranges = self.clean_ranges(msg)

        front_distance = self.min_in_sector_by_angle(
            ranges, msg,
            math.radians(-15.0),
            math.radians(15.0)
        )

        left_distance = self.min_in_sector_by_angle(
            ranges, msg,
            math.radians(75.0),
            math.radians(105.0)
        )

        right_distance = self.min_in_sector_by_angle(
            ranges, msg,
            math.radians(-105.0),
            math.radians(-75.0)
        )

        distances_msg = Vector3()
        distances_msg.x = front_distance
        distances_msg.y = left_distance
        distances_msg.z = right_distance
        self.distances_pub.publish(distances_msg)

        obstacle_msg = Bool()
        obstacle_msg.data = front_distance < self.obstacle_threshold
        self.obstacle_pub.publish(obstacle_msg)

        self.get_logger().info(
            f'front={front_distance:.2f}, '
            f'left={left_distance:.2f}, '
            f'right={right_distance:.2f}, '
            f'obstacle={obstacle_msg.data}'
        )


def main(args=None):
    rclpy.init(args=args)
    node = PerceptionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()