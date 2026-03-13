from setuptools import setup

package_name = 'vehicle_interface'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Ahmed',
    maintainer_email='ahmed@example.com',
    description='Vehicle interface package',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)
