import rclpy
from rclpy.node import Node


class SensorNode(Node):
    def __init__(self):
        super().__init__('sensor_node')
        self.get_logger().info('Sensor driver node started')
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.get_logger().debug('Sensor heartbeat')


def main(args=None):
    rclpy.init(args=args)
    node = SensorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
