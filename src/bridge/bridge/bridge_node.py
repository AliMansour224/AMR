import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from interfaces.msg import BridgeStatus, VehicleStatus


class BridgeNode(Node):
    def __init__(self):
        super().__init__('bridge_node')

        self.cmd_sub = self.create_subscription(
            Twist,
            '/cmd_vel',
            self.cmd_callback,
            10
        )

        self.bridge_status_pub = self.create_publisher(
            BridgeStatus,
            '/bridge_status',
            10
        )

        self.vehicle_status_pub = self.create_publisher(
            VehicleStatus,
            '/vehicle_status',
            10
        )

        self.tx_count = 0
        self.rx_count = 0
        self.crc_error_count = 0
        self.timeout_count = 0

        self.timer = self.create_timer(0.1, self.publish_bridge_status)

        self.get_logger().info('Bridge node started.')

    def cmd_callback(self, msg: Twist):
        self.tx_count += 1
        self.get_logger().info(
            f'Received /cmd_vel: linear.x={msg.linear.x:.3f}, angular.z={msg.angular.z:.3f}'
        )

    def publish_bridge_status(self):
        msg = BridgeStatus()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.connected = False
        msg.command_stream_active = self.tx_count > 0
        msg.tx_count = self.tx_count
        msg.rx_count = self.rx_count
        msg.crc_error_count = self.crc_error_count
        msg.timeout_count = self.timeout_count
        msg.state = 'stub'
        self.bridge_status_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = BridgeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()