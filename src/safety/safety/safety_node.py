import rclpy
from rclpy.node import Node


class SafetyNode(Node):
    def __init__(self):
        super().__init__('safety_node')
        self.get_logger().info('Safety node started')
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.get_logger().debug('Safety heartbeat')


def main(args=None):
    rclpy.init(args=args)
    node = SafetyNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
