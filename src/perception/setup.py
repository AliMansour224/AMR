import os

from setuptools import find_packages, setup
from glob import glob

package_name = 'perception'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (
            os.path.join('share', package_name, 'config'),
            glob(os.path.join(package_name, 'config', '*.yaml')),
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ahmed',
    maintainer_email='ahmed@todo.todo',
    description='Perception package',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'perception_node = perception.perception_node:main',
            'lidar_perception_node = perception.lidar_perception_node:main',
        ],
    },
)
