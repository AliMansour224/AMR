#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan


class LidarDriver(Node):
    def __init__(self):
        super().__init__('lidar_driver')

        self.sub = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10
        )

        self.pub = self.create_publisher(
            LaserScan,
            '/sensors/lidar/scan',
            10
        )

        self.get_logger().info('Lidar driver started.')

    def scan_callback(self, msg: LaserScan):
        out = LaserScan()
        out.header = msg.header
        out.header.frame_id = 'lidar_link'

        out.angle_min = msg.angle_min
        out.angle_max = msg.angle_max
        out.angle_increment = msg.angle_increment
        out.time_increment = msg.time_increment
        out.scan_time = msg.scan_time
        out.range_min = msg.range_min
        out.range_max = msg.range_max
        out.ranges = msg.ranges
        out.intensities = msg.intensities

        self.pub.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = LidarDriver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()