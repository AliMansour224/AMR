from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    lidar_driver_node = Node(
        package='sensor_drivers',
        executable='lidar_driver',
        name='lidar_driver',
        output='screen'
    )

    imu_driver_node = Node(
        package='sensor_drivers',
        executable='imu_driver',
        name='imu_driver',
        output='screen'
    )

    odometry_bridge_node = Node(
        package='sensor_drivers',
        executable='odometry_bridge',
        name='odometry_bridge',
        output='screen'
    )

    return LaunchDescription([
        lidar_driver_node,
        imu_driver_node,
        odometry_bridge_node
    ])
