#!/usr/bin/env python3

import math

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist


class ReactiveDriver(Node):
    def __init__(self):
        super().__init__('reactive_driver')

        self.scan_sub = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10
        )

        self.cmd_pub = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )

        self.front_clear_distance = 1.0
        self.forward_speed = 0.5
        self.turn_speed = 0.8

        self.get_logger().info('Reactive driver node started.')

    def scan_callback(self, msg: LaserScan):
        ranges = list(msg.ranges)

        if not ranges:
            return

        valid_ranges = []
        for r in ranges:
            if math.isfinite(r) and msg.range_min < r < msg.range_max:
                valid_ranges.append(r)
            else:
                valid_ranges.append(float('inf'))

        center_index = len(valid_ranges) // 2
        window_size = 20

        front_ranges = (
            valid_ranges[max(0, center_index - window_size): center_index + window_size] +
            valid_ranges[0:window_size] +
            valid_ranges[-window_size:]
        )

        min_front_distance = min(front_ranges) if front_ranges else float('inf')

        cmd = Twist()

        if min_front_distance > self.front_clear_distance:
            cmd.linear.x = self.forward_speed
            cmd.angular.z = 0.0
        else:
            cmd.linear.x = 0.0
            cmd.angular.z = self.turn_speed

        self.cmd_pub.publish(cmd)


def main(args=None):
    rclpy.init(args=args)
    node = ReactiveDriver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()