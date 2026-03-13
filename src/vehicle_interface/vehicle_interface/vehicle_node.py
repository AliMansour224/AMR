import rclpy
from rclpy.node import Node


class VehicleInterfaceNode(Node):
    def __init__(self):
        super().__init__('vehicle_interface_node')
        self.get_logger().info('Vehicle interface node started')
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.get_logger().debug('Vehicle interface heartbeat')


def main(args=None):
    rclpy.init(args=args)
    node = VehicleInterfaceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
