from setuptools import setup

package_name = 'description'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/urdf', ['urdf/robot.urdf.xacro']),
        ('share/' + package_name + '/launch', ['launch/view_description.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Ahmed',
    maintainer_email='ahmedlearningfinnish@gmail.com',
    description='Robot description package with URDF/Xacro and TF frame definitions.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={},
)