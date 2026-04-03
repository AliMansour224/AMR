from setuptools import find_packages
from setuptools import setup

setup(
    name='autonomy_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('autonomy_msgs', 'autonomy_msgs.*')),
)
