#!/usr/bin/env python3

import math

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan


class MockLidar(Node):
    def __init__(self):
        super().__init__('mock_lidar')

        self.pub = self.create_publisher(
            LaserScan,
            '/sensors/lidar/scan',
            10
        )

        self.timer = self.create_timer(0.1, self.publish_scan)

        # Test mode
        self.mode = 'clear'  # Options: 'clear', 'front_obstacle', 'left_obstacle', 'right_obstacle', 'noisy_front'

        self.angle_min = -math.pi
        self.angle_max = math.pi
        self.num_samples = 360
        self.angle_increment = (self.angle_max - self.angle_min) / self.num_samples

        self.get_logger().info(f'Mock LiDAR started. Mode: {self.mode}')

    def publish_scan(self):
        msg = LaserScan()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'lidar_link'

        msg.angle_min = self.angle_min
        msg.angle_max = self.angle_max
        msg.angle_increment = self.angle_increment
        msg.time_increment = 0.0
        msg.scan_time = 0.1
        msg.range_min = 0.1
        msg.range_max = 10.0

        ranges = [5.0] * self.num_samples

        if self.mode == 'clear':
            pass

        elif self.mode == 'front_obstacle':
            center = self.num_samples // 2
            for i in range(center - 15, center + 15):
                if 0 <= i < self.num_samples:
                    ranges[i] = 0.8

        elif self.mode == 'left_obstacle':
            left_center = (3 * self.num_samples) // 4
            for i in range(left_center - 15, left_center + 15):
                if 0 <= i < self.num_samples:
                    ranges[i] = 0.6

        elif self.mode == 'right_obstacle':
            right_center = self.num_samples // 4
            for i in range(right_center - 15, right_center + 15):
                if 0 <= i < self.num_samples:
                    ranges[i] = 0.6

        elif self.mode == 'noisy_front':
            center = self.num_samples // 2
            for i in range(center - 20, center + 20):
                if 0 <= i < self.num_samples:
                    ranges[i] = 0.7
            ranges[10] = float('inf')
            ranges[20] = float('nan')
            ranges[30] = 0.1
            ranges[40] = 0.05

        msg.ranges = ranges
        msg.intensities = [1.0] * self.num_samples

        self.pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = MockLidar()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()