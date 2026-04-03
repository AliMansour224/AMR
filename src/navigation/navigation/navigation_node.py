#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3
from std_msgs.msg import Bool


class NavigationNode(Node):
    def __init__(self):
        super().__init__('navigation_node')

        self.distances_sub = self.create_subscription(
            Vector3,
            '/perception/distances',
            self.distances_callback,
            10
        )

        self.obstacle_sub = self.create_subscription(
            Bool,
            '/perception/obstacle_ahead',
            self.obstacle_callback,
            10
        )

        self.plan_pub = self.create_publisher(
            Vector3,
            '/planning/cmd',
            10
        )

        self.latest_distances = Vector3()
        self.obstacle_ahead = False

        self.get_logger().info('Planning node started.')

    def distances_callback(self, msg: Vector3):
        self.latest_distances = msg
        self.publish_plan()

    def obstacle_callback(self, msg: Bool):
        self.obstacle_ahead = msg.data
        self.publish_plan()

    def publish_plan(self):
        cmd = Vector3()

        if self.obstacle_ahead:
            cmd.x = 0.0
            cmd.y = 0.0
            cmd.z = 0.0
        else:
            cmd.x = 0.5
            cmd.y = 0.0
            cmd.z = 0.0

        self.plan_pub.publish(cmd)
        self.get_logger().info(
            f'Publishing plan: x={cmd.x}, z={cmd.z}, obstacle={self.obstacle_ahead}'
        )


def main(args=None):
    rclpy.init(args=args)
    node = NavigationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()