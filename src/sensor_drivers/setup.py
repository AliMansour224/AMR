from setuptools import find_packages, setup

package_name = 'sensor_drivers'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ahmed',
    maintainer_email='ahmed@todo.todo',
    description='Sensor drivers package',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'lidar_driver = sensor_drivers.lidar_driver:main',
            'imu_driver = sensor_drivers.imu_driver:main',
            'odometry_bridge = sensor_drivers.odometry_bridge:main'
        ],
    },
)