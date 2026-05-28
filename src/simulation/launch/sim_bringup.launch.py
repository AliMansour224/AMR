import os

from launch import LaunchDescription
from launch.actions import ExecuteProcess, SetEnvironmentVariable, TimerAction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_path = get_package_share_directory('simulation')
    world_path = os.path.join(pkg_path, 'worlds', 'adc_track_v1.sdf')
    sparkx_model_path = os.path.join(pkg_path, 'models', 'sparkx_car', 'model.sdf')
    models_path = os.path.join(pkg_path, 'models')
    bridge_config_path = os.path.join(pkg_path, 'config', 'ros_gz_bridges.yaml')
    rsp_launch_path = os.path.join(pkg_path, 'launch', 'rsp.launch.py')

    gz_resource_path = models_path
    if os.environ.get('GZ_SIM_RESOURCE_PATH'):
        gz_resource_path = models_path + ':' + os.environ.get('GZ_SIM_RESOURCE_PATH')

    return LaunchDescription([
        SetEnvironmentVariable(
            name='GZ_SIM_RESOURCE_PATH',
            value=gz_resource_path
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(rsp_launch_path),
            launch_arguments={'use_sim_time': 'true'}.items()
        ),

        ExecuteProcess(
            cmd=['gz', 'sim', '-r', '-v', '4', world_path],
            output='screen'
        ),

        TimerAction(
            period=6.0,
            actions=[
                ExecuteProcess(
                    cmd=[
                        'gz', 'service',
                        '-s', '/world/adc_track_v1/create',
                        '--reqtype', 'gz.msgs.EntityFactory',
                        '--reptype', 'gz.msgs.Boolean',
                        '--timeout', '10000',
                        '--req',
                        f'sdf_filename: "{sparkx_model_path}" name: "sparkx_car" pose: {{position: {{x: 5.0, y: -4.0, z: 0.1}}, orientation: {{x: 0, y: 0, z: 0.7068, w: 0.7074}}}}',
                    ],
                    output='screen'
                ),
            ]
        ),

        TimerAction(
            period=10.0,
            actions=[
                Node(
                    package='ros_gz_bridge',
                    executable='bridge_node',
                    name='ros_gz_bridge',
                    output='screen',
                    parameters=[
                        {'config_file': bridge_config_path},
                        {'use_sim_time': True},
                    ]
                ),
            ]
        ),
    ])