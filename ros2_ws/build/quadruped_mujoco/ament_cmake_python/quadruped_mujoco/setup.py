from setuptools import find_packages
from setuptools import setup

setup(
    name='quadruped_mujoco',
    version='0.1.0',
    packages=find_packages(
        include=('quadruped_mujoco', 'quadruped_mujoco.*')),
)
