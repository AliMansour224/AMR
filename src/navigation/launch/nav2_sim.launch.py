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
    velocity_smoother_params = os.path.join(navigation_dir, 'config', 'nav2_velocity_smoother.yaml')
    safety_supervisor_params = os.path.join(navigation_dir, 'config', 'safety_supervisor.yaml')

    planner_server = Node(
        package='nav2_planner',
        executable='planner_server',
        name='planner_server',
        output='screen',
        parameters=[planner_params, costmap_params, {'use_sim_time': True}],
    )

    controller_server = Node(
    package='nav2_controller',
    executable='controller_server',
    name='controller_server',
    output='screen',
    parameters=[controller_params, costmap_params, {'use_sim_time': True}],
    remappings=[('cmd_vel', '/cmd_vel_nav')],
    )


    bt_navigator = Node(
        package='nav2_bt_navigator',
        executable='bt_navigator',
        name='bt_navigator',
        output='screen',
        parameters=[bt_params, {'use_sim_time': True}],
    )

    behavior_server = Node(
        package='nav2_behaviors',
        executable='behavior_server',
        name='behavior_server',
        output='screen',
        parameters=[behavior_params, {'use_sim_time': True}],
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
                'behavior_server',
                'velocity_smoother'
            ]
        }],
    )
    velocity_smoother = Node(
        package='nav2_velocity_smoother',
        executable='velocity_smoother',
        name='velocity_smoother',
        output='screen',
        parameters=[velocity_smoother_params, {'use_sim_time': True}],
        remappings=[
            ('cmd_vel', '/cmd_vel_nav'),
            ('cmd_vel_smoothed', '/cmd_vel_smoothed')
        ],
    )

    safety_supervisor = Node(
        package='navigation',
        executable='safety_supervisor',
        name='safety_supervisor',
        output='screen',
        parameters=[safety_supervisor_params, {'use_sim_time': True}],
    )

    return LaunchDescription([
        planner_server,
        controller_server,
        bt_navigator,
        behavior_server,
        lifecycle_manager,
        velocity_smoother,
        safety_supervisor,
    ])