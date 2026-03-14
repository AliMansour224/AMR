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

        self.get_logger().info('Perception node started.')

    def clean_ranges(self, msg: LaserScan):
        cleaned = []
        for r in msg.ranges:
            if math.isfinite(r) and msg.range_min < r < msg.range_max:
                cleaned.append(r)
            else:
                cleaned.append(float('inf'))
        return cleaned

    def min_in_sector(self, ranges, start_idx, end_idx):
        sector = ranges[start_idx:end_idx]
        if not sector:
            return float('inf')
        return min(sector)

    def scan_callback(self, msg: LaserScan):
        ranges = self.clean_ranges(msg)

        n = len(ranges)
        if n == 0:
            return

        center = n // 2
        window = 20

        front_sector = (
            ranges[max(0, center - window): center + window] +
            ranges[0:window] +
            ranges[-window:]
        )

        left_start = n // 4 - window
        left_end = n // 4 + window

        right_start = (3 * n) // 4 - window
        right_end = (3 * n) // 4 + window

        left_sector = ranges[max(0, left_start): min(n, left_end)]
        right_sector = ranges[max(0, right_start): min(n, right_end)]

        front_distance = min(front_sector) if front_sector else float('inf')
        left_distance = min(left_sector) if left_sector else float('inf')
        right_distance = min(right_sector) if right_sector else float('inf')

        distances_msg = Vector3()
        distances_msg.x = front_distance
        distances_msg.y = left_distance
        distances_msg.z = right_distance
        self.distances_pub.publish(distances_msg)

        obstacle_msg = Bool()
        obstacle_msg.data = front_distance < self.obstacle_threshold
        self.obstacle_pub.publish(obstacle_msg)


def main(args=None):
    rclpy.init(args=args)
    node = PerceptionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()