from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource

from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():

    simulation_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('simulation'),
                'launch',
                'sim_bringup.launch.py'
            )
        )
    )

    perception_node = Node(
        package='perception',
        executable='perception_node',
        name='perception_node',
        output='screen'
    )

    planning_node = Node(
        package='planning',
        executable='planning_node',
        name='planning_node',
        output='screen'
    )

    control_node = Node(
        package='control',
        executable='control_node',
        name='control_node',
        output='screen'
    )

    return LaunchDescription([
        simulation_launch,
        perception_node,
        planning_node,
        control_node
    ])