#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3, Twist


class ControlNode(Node):
    def __init__(self):
        super().__init__('control_node')

        self.plan_sub = self.create_subscription(
            Vector3,
            '/planning/cmd',
            self.plan_callback,
            10
        )

        self.cmd_pub = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )

        self.get_logger().info('Control node started.')

    def plan_callback(self, msg: Vector3):
        cmd = Twist()
        cmd.linear.x = msg.x
        cmd.linear.y = 0.0
        cmd.linear.z = 0.0
        cmd.angular.x = 0.0
        cmd.angular.y = 0.0
        cmd.angular.z = msg.z

        self.cmd_pub.publish(cmd)


def main(args=None):
    rclpy.init(args=args)
    node = ControlNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()