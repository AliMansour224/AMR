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
    map_yaml_file = os.path.join(pkg_path, 'maps', 'adc_track_v1_map.yaml')


    frame_normalizer_node = frame_normalizer_node = Node(
      package='localization',
      executable='frame_normalizer_node',
      name='frame_normalizer',
      output='screen',
      parameters=[{
        'use_sim_time': True,
        'scan_in': '/scan',
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
        parameters=[ekf_config, {'use_sim_time': True}],
    )

    slam_node = LifecycleNode(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        namespace='',
        output='screen',
        parameters=[slam_config, {'use_sim_time': True}]
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
        frame_normalizer_node,
        ekf_node,
        slam_node,
        configure_slam,
        activate_slam,
    ])