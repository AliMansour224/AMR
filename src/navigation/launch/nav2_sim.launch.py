from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    navigation_dir = get_package_share_directory('navigation')

    planner_params = os.path.join(navigation_dir, 'config', 'nav2_planner.yaml')
    controller_params = os.path.join(navigation_dir, 'config', 'nav2_controller_dwb.yaml')
    costmap_params = os.path.join(navigation_dir, 'config', 'nav2_costmaps.yaml')
    bt_params = os.path.join(navigation_dir, 'config', 'nav2_bt_navigator.yaml')
    behavior_params = os.path.join(navigation_dir, 'config', 'nav2_behavior.yaml')

    planner_server = Node(
        package='nav2_planner',
        executable='planner_server',
        name='planner_server',
        output='screen',
        parameters=[planner_params, costmap_params],
    )

    controller_server = Node(
        package='nav2_controller',
        executable='controller_server',
        name='controller_server',
        output='screen',
        parameters=[controller_params, costmap_params],
    )

    bt_navigator = Node(
        package='nav2_bt_navigator',
        executable='bt_navigator',
        name='bt_navigator',
        output='screen',
        parameters=[bt_params],
    )

    behavior_server = Node(
        package='nav2_behaviors',
        executable='behavior_server',
        name='behavior_server',
        output='screen',
        parameters=[behavior_params],
    )

    lifecycle_manager = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_navigation',
        output='screen',
        parameters=[{
            'use_sim_time': True,
            'autostart': True,
            'node_names': [
                'planner_server',
                'controller_server',
                'bt_navigator',
                'behavior_server'
            ]
        }],
    )

    return LaunchDescription([
        planner_server,
        controller_server,
        bt_navigator,
        behavior_server,
        lifecycle_manager,
    ])