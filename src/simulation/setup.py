from setuptools import find_packages, setup
import os           # <--- Make sure this is here
from glob import glob # <--- Make sure this is here

package_name = 'simulation'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # This tells colcon to copy your launch files
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        # This tells colcon to copy your urdf files (IMPORTANT)
        (os.path.join('share', package_name, 'urdf'), glob('urdf/*.xacro')),
        # This tells colcon to copy your world files
        (os.path.join('share', package_name, 'worlds'), glob('worlds/*.sdf')),
        # lidar_test model
        (os.path.join('share', package_name, 'models', 'lidar_test'), glob('models/lidar_test/*')),
        #sparkx_car model
        (os.path.join('share', package_name, 'models', 'sparkx_car'), glob('models/sparkx_car/*')),
        #imu_test model
        (os.path.join('share', package_name, 'models', 'imu_test'), glob('models/imu_test/*')),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ahmed',
    maintainer_email='ahmed@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
    },
)