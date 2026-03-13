import rclpy
from rclpy.node import Node


class LocalizationNode(Node):
    def __init__(self):
        super().__init__('localization_node')
        self.get_logger().info('Localization node started')
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.get_logger().debug('Localization heartbeat')


def main(args=None):
    rclpy.init(args=args)
    node = LocalizationNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
