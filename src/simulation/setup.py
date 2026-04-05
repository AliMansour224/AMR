from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'simulation'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),

        # Launch files
        (os.path.join('share', package_name, 'launch'),
         glob('launch/*.launch.py')),

        # Config files
        (os.path.join('share', package_name, 'config'),
         glob('config/*.yaml')),

        # URDF/Xacro files
        (os.path.join('share', package_name, 'urdf'),
         glob('urdf/*.xacro')),

        # World files
        (os.path.join('share', package_name, 'worlds'),
         glob('worlds/*.sdf')),

        # Model files
        (os.path.join('share', package_name, 'models', 'lidar_test'),
         glob('models/lidar_test/*')),
        (os.path.join('share', package_name, 'models', 'sparkx_car'),
         glob('models/sparkx_car/*')),
        (os.path.join('share', package_name, 'models', 'imu_test'),
         glob('models/imu_test/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Ahmed',
    maintainer_email='ahmed@example.com',
    description='Gazebo simulation environment for SparkX autonomy stack',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)