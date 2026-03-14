import os

from launch import LaunchDescription
from launch.actions import ExecuteProcess, SetEnvironmentVariable, TimerAction
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_path = get_package_share_directory('simulation')
    world_path = os.path.join(pkg_path, 'worlds', 'empty_world.sdf')
    sparkx_model_path = os.path.join(pkg_path, 'models', 'sparkx_car', 'model.sdf')
    lidar_model_path = os.path.join(pkg_path, 'models', 'lidar_test', 'model.sdf')
    models_path = os.path.join(pkg_path, 'models')

    return LaunchDescription([
        SetEnvironmentVariable(
            name='GZ_SIM_RESOURCE_PATH',
            value=models_path + ':' + os.environ.get('GZ_SIM_RESOURCE_PATH', '')
        ),

        ExecuteProcess(
            cmd=['gz', 'sim', '-s', '--headless-rendering', '-r', world_path],
            output='screen'
        ),

        TimerAction(
            period=2.0,
            actions=[
                ExecuteProcess(
                    cmd=[
                        'gz', 'service', '-s', '/world/empty/create',
                        '--reqtype', 'gz.msgs.EntityFactory',
                        '--reptype', 'gz.msgs.Boolean',
                        '--timeout', '3000',
                        '--req',
                        f'sdf_filename: "{sparkx_model_path}" name: "sparkx_car"'
                    ],
                    output='screen'
                ),
                ExecuteProcess(
                    cmd=[
                        'gz', 'service', '-s', '/world/empty/create',
                        '--reqtype', 'gz.msgs.EntityFactory',
                        '--reptype', 'gz.msgs.Boolean',
                        '--timeout', '3000',
                        '--req',
                        f'sdf_filename: "{lidar_model_path}" name: "lidar_test"'
                    ],
                    output='screen'
                ),

            ]
        ),

        TimerAction(
            period=3.0,
            actions=[
                ExecuteProcess(
                    cmd=[
                        'ros2', 'run', 'ros_gz_bridge', 'parameter_bridge',
                        '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan'
                    ],
                    output='screen'
                ),
                ExecuteProcess(
                    cmd=[
                        'ros2', 'run', 'ros_gz_bridge', 'parameter_bridge',
                        '/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist'
                    ],
                    output='screen'
                ),
                ExecuteProcess(
                    cmd=[
                        'ros2', 'run', 'ros_gz_bridge', 'parameter_bridge',
                        '/model/sparkx_car/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry'
                    ],
                    output='screen'
                ),
                ExecuteProcess(
                    cmd=[
                       'ros2', 'run', 'ros_gz_bridge', 'parameter_bridge',
                       '/imu@sensor_msgs/msg/Imu[gz.msgs.IMU'
                    ],
                    output='screen'
            ),

            ]
        ),
    ])