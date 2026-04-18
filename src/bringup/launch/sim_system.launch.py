import os

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    sim_pkg = get_package_share_directory('simulation')
    localization_pkg = get_package_share_directory('localization')
    navigation_pkg = get_package_share_directory('navigation')

    sim_launch = os.path.join(sim_pkg, 'launch', 'sim_bringup.launch.py')
    localization_launch = os.path.join(localization_pkg, 'launch', 'sim_localization.launch.py')
    navigation_launch = os.path.join(navigation_pkg, 'launch', 'nav2_sim.launch.py')

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(sim_launch)
        ),

        # Delay localization so Gazebo, robot spawn, and bridge are already alive
        TimerAction(
            period=12.0,
            actions=[
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(localization_launch)
                )
            ]
        ),

        # Delay navigation until localization and TF are already alive
        TimerAction(
            period=18.0,
            actions=[
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(navigation_launch)
                )
            ]
        ),
    ])