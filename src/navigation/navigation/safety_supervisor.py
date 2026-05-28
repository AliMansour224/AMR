import math
from typing import Optional

import rclpy
from rclpy.node import Node
from rclpy.duration import Duration

from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from std_msgs.msg import Bool


class SafetySupervisor(Node):
    def __init__(self) -> None:
        super().__init__('safety_supervisor')

        self.declare_parameter('cmd_in_topic', '/cmd_vel_smoothed')
        self.declare_parameter('cmd_out_topic', '/cmd_vel')
        self.declare_parameter('scan_topic', '/scan')
        self.declare_parameter('odom_topic', '/odometry/filtered')
        self.declare_parameter('scan_timeout_sec', 0.5)
        self.declare_parameter('odom_timeout_sec', 0.5)
        self.declare_parameter('publish_rate_hz', 20.0)

        self.declare_parameter('force_scan_fail', False)
        self.declare_parameter('force_odom_fail', False)

        cmd_in_topic = self.get_parameter('cmd_in_topic').get_parameter_value().string_value
        cmd_out_topic = self.get_parameter('cmd_out_topic').get_parameter_value().string_value
        scan_topic = self.get_parameter('scan_topic').get_parameter_value().string_value
        odom_topic = self.get_parameter('odom_topic').get_parameter_value().string_value
        self.scan_timeout_sec = self.get_parameter('scan_timeout_sec').get_parameter_value().double_value
        self.odom_timeout_sec = self.get_parameter('odom_timeout_sec').get_parameter_value().double_value
        publish_rate_hz = self.get_parameter('publish_rate_hz').get_parameter_value().double_value

        self.last_cmd: Twist = Twist()
        self.last_scan_time = None
        self.last_odom_time = None

        self.cmd_sub = self.create_subscription(Twist, cmd_in_topic, self.cmd_callback, 10)
        self.scan_sub = self.create_subscription(LaserScan, scan_topic, self.scan_callback, 10)
        self.odom_sub = self.create_subscription(Odometry, odom_topic, self.odom_callback, 10)

        self.cmd_pub = self.create_publisher(Twist, cmd_out_topic, 10)
        self.safe_pub = self.create_publisher(Bool, '/safety_status', 10)

        timer_period = 1.0 / publish_rate_hz
        self.timer = self.create_timer(timer_period, self.publish_safe_cmd)

        self.get_logger().info('Safety supervisor started.')

    def cmd_callback(self, msg: Twist) -> None:
        self.last_cmd = msg

    def scan_callback(self, _msg: LaserScan) -> None:
        self.last_scan_time = self.get_clock().now()

    def odom_callback(self, _msg: Odometry) -> None:
        self.last_odom_time = self.get_clock().now()

    def topic_fresh(self, last_time: Optional[rclpy.time.Time], timeout_sec: float) -> bool:
        if last_time is None:
            return False
        age = self.get_clock().now() - last_time
        return age <= Duration(seconds=timeout_sec)

    def publish_safe_cmd(self) -> None:
        force_scan_fail = self.get_parameter('force_scan_fail').get_parameter_value().bool_value
        force_odom_fail = self.get_parameter('force_odom_fail').get_parameter_value().bool_value

        scan_ok = self.topic_fresh(self.last_scan_time, self.scan_timeout_sec) and not force_scan_fail
        odom_ok = self.topic_fresh(self.last_odom_time, self.odom_timeout_sec) and not force_odom_fail
        
        safe = scan_ok and odom_ok

        self.safe_pub.publish(Bool(data=safe))

        if safe:
            self.cmd_pub.publish(self.last_cmd)
        else:
            self.cmd_pub.publish(Twist())


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SafetySupervisor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()