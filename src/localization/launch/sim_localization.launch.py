import os

from launch import LaunchDescription
from launch.actions import EmitEvent, RegisterEventHandler, LogInfo
from launch.events import matches_action
from launch_ros.actions import Node, LifecycleNode
from launch_ros.event_handlers import OnStateTransition
from launch_ros.events.lifecycle import ChangeState
from lifecycle_msgs.msg import Transition
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_path = get_package_share_directory('localization')
    slam_config = os.path.join(pkg_path, 'config', 'slam_mapping.yaml')
    ekf_config = os.path.join(pkg_path, 'config', 'ekf.yaml')

    mock_lidar_node = mock_lidar_node = mock_lidar_node = Node(
      package='sensor_drivers',
      executable='mock_lidar',
      name='mock_lidar',
      output='screen',
      parameters=[{
        'use_sim_time': True,
        'scan_topic': '/sensors/lidar/scan',
        'odom_topic': '/odometry/filtered',
        'frame_id': 'lidar_link',
        'publish_rate_hz': 10.0,
        'angle_min': -3.14159,
        'angle_max': 3.14159,
        'num_beams': 360,
        'range_min': 0.12,
        'range_max': 12.0,
        'room_min_x': -8.0,
        'room_max_x': 8.0,
        'room_min_y': -6.0,
        'room_max_y': 6.0,
    }]
)

    frame_normalizer_node = frame_normalizer_node = Node(
      package='localization',
      executable='frame_normalizer_node',
      name='frame_normalizer',
      output='screen',
      parameters=[{
        'use_sim_time': True,
        'scan_in': '/sensors/lidar/scan',
        'scan_out': '/scan_localization',
        'odom_in': '/wheel_odom',
        'odom_out': '/wheel_odom_localization',
        'scan_frame_id': 'lidar_link',
        'odom_frame_id': 'odom',
        'base_frame_id': 'base_link',
    }],
)

    ekf_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[ekf_config],
    )

    slam_node = LifecycleNode(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        namespace='',
        output='screen',
        parameters=[slam_config, {'use_sim_time': True}],
    )

    configure_slam = EmitEvent(
        event=ChangeState(
            lifecycle_node_matcher=matches_action(slam_node),
            transition_id=Transition.TRANSITION_CONFIGURE,
        )
    )

    activate_slam = RegisterEventHandler(
        OnStateTransition(
            target_lifecycle_node=slam_node,
            start_state='configuring',
            goal_state='inactive',
            entities=[
                LogInfo(msg='[LifecycleLaunch] slam_toolbox activating'),
                EmitEvent(
                    event=ChangeState(
                        lifecycle_node_matcher=matches_action(slam_node),
                        transition_id=Transition.TRANSITION_ACTIVATE,
                    )
                ),
            ],
        )
    )

    return LaunchDescription([
        mock_lidar_node,
        frame_normalizer_node,
        ekf_node,
        slam_node,
        configure_slam,
        activate_slam,
    ])