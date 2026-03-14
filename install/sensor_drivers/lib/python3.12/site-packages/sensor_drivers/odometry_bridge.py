#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster


class OdometryBridge(Node):
    def __init__(self):
        super().__init__('odometry_bridge')

        self.subscription = self.create_subscription(
            Odometry,
            '/model/sparkx_car/odometry',
            self.odometry_callback,
            10
        )

        self.odom_publisher = self.create_publisher(
            Odometry,
            '/sensors/odometry',
            10
        )

        self.tf_broadcaster = TransformBroadcaster(self)

        self.get_logger().info('Odometry bridge node started.')

    def odometry_callback(self, msg: Odometry):
        # Create cleaned odometry message
        odom_msg = Odometry()

        odom_msg.header.stamp = msg.header.stamp
        odom_msg.header.frame_id = 'odom'
        odom_msg.child_frame_id = 'base_link'

        odom_msg.pose = msg.pose
        odom_msg.twist = msg.twist

        self.odom_publisher.publish(odom_msg)

        # Publish odom -> base_link TF
        transform = TransformStamped()
        transform.header.stamp = msg.header.stamp
        transform.header.frame_id = 'odom'
        transform.child_frame_id = 'base_link'

        transform.transform.translation.x = msg.pose.pose.position.x
        transform.transform.translation.y = msg.pose.pose.position.y
        transform.transform.translation.z = msg.pose.pose.position.z

        transform.transform.rotation = msg.pose.pose.orientation

        self.tf_broadcaster.sendTransform(transform)


def main(args=None):
    rclpy.init(args=args)
    node = OdometryBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
