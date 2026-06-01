import copy

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from sensor_msgs.msg import LaserScan, Imu
from nav_msgs.msg import Odometry


class FrameNormalizerNode(Node):
    def __init__(self):
        super().__init__('frame_normalizer')

        self.declare_parameter('scan_in', '/scan')
        self.declare_parameter('scan_out', '/scan_localization')
        self.declare_parameter('odom_in', '/wheel_odom')
        self.declare_parameter('odom_out', '/wheel_odom_localization')
        self.declare_parameter('scan_frame_id', 'lidar_link')
        self.declare_parameter('odom_frame_id', 'odom')
        self.declare_parameter('base_frame_id', 'base_link')
        self.declare_parameter('imu_in', '/imu/data')
        self.declare_parameter('imu_out', '/imu_localization')

        scan_in = self.get_parameter('scan_in').get_parameter_value().string_value
        scan_out = self.get_parameter('scan_out').get_parameter_value().string_value
        odom_in = self.get_parameter('odom_in').get_parameter_value().string_value
        odom_out = self.get_parameter('odom_out').get_parameter_value().string_value
        imu_in = self.get_parameter('imu_in').get_parameter_value().string_value
        imu_out = self.get_parameter('imu_out').get_parameter_value().string_value

        self.scan_frame_id = self.get_parameter('scan_frame_id').get_parameter_value().string_value
        self.odom_frame_id = self.get_parameter('odom_frame_id').get_parameter_value().string_value
        self.base_frame_id = self.get_parameter('base_frame_id').get_parameter_value().string_value

        sensor_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )

        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )

        self.scan_pub = self.create_publisher(LaserScan, scan_out, sensor_qos)
        self.odom_pub = self.create_publisher(Odometry, odom_out, odom_qos)
        self.imu_pub = self.create_publisher(Imu, imu_out, sensor_qos)

        self.scan_sub = self.create_subscription(
            LaserScan,
            scan_in,
            self.scan_callback,
            sensor_qos,
        )

        self.odom_sub = self.create_subscription(
            Odometry,
            odom_in,
            self.odom_callback,
            odom_qos,
        )

        self.imu_sub = self.create_subscription(
            Imu,
            imu_in,
            self.imu_callback,
            sensor_qos,
        )

        self.get_logger().info(f'Normalizing {scan_in} -> {scan_out} with frame_id={self.scan_frame_id}')
        self.get_logger().info(
            f'Normalizing {odom_in} -> {odom_out} with frame_id={self.odom_frame_id}, '
            f'child_frame_id={self.base_frame_id}'
        )

    def scan_callback(self, msg: LaserScan) -> None:
        out = copy.deepcopy(msg)
        out.header.frame_id = self.scan_frame_id
        self.scan_pub.publish(out)

    def odom_callback(self, msg: Odometry) -> None:
        out = copy.deepcopy(msg)
        out.header.frame_id = self.odom_frame_id
        out.child_frame_id = self.base_frame_id
        self.odom_pub.publish(out)

    def imu_callback(self, msg: Imu) -> None:
        out = copy.deepcopy(msg)
        out.header.frame_id = self.base_frame_id
        # Gazebo Sim IMU sometimes outputs opposite yaw velocity convention.
        # Invert it so it matches wheel odometry and ROS ENU standard!
        out.angular_velocity.z = -msg.angular_velocity.z
        self.imu_pub.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = FrameNormalizerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()