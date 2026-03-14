#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu


class ImuDriver(Node):
    def __init__(self):
        super().__init__('imu_driver')

        self.sub = self.create_subscription(
            Odometry,
            '/model/sparkx_car/odometry',
            self.odom_callback,
            10
        )

        self.pub = self.create_publisher(
            Imu,
            '/sensors/imu/data',
            10
        )

        self.get_logger().info('IMU driver started.')

    def odom_callback(self, msg: Odometry):
        imu_msg = Imu()

        imu_msg.header.stamp = msg.header.stamp
        imu_msg.header.frame_id = 'imu_link'

        # Copy orientation from odometry pose
        imu_msg.orientation = msg.pose.pose.orientation

        # Basic covariance placeholders
        imu_msg.orientation_covariance = [
            0.01, 0.0, 0.0,
            0.0, 0.01, 0.0,
            0.0, 0.0, 0.01
        ]

        # Use angular velocity from odometry twist
        imu_msg.angular_velocity = msg.twist.twist.angular
        imu_msg.angular_velocity_covariance = [
            0.01, 0.0, 0.0,
            0.0, 0.01, 0.0,
            0.0, 0.0, 0.01
        ]

        # Placeholder linear acceleration
        imu_msg.linear_acceleration.x = 0.0
        imu_msg.linear_acceleration.y = 0.0
        imu_msg.linear_acceleration.z = 9.81
        imu_msg.linear_acceleration_covariance = [
            0.1, 0.0, 0.0,
            0.0, 0.1, 0.0,
            0.0, 0.0, 0.1
        ]

        self.pub.publish(imu_msg)


def main(args=None):
    rclpy.init(args=args)
    node = ImuDriver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
