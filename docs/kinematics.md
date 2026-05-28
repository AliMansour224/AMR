## Task 1.4 frozen baseline

Frames:
- map
- odom
- base_link
- lidar_link

TF ownership:
- map -> odom: slam_toolbox
- odom -> base_link: robot_localization EKF
- base_link -> lidar_link: robot_state_publisher

Robot:
- diff drive
- chassis: 0.3 x 0.3 x 0.15 m
- track width: 0.35 m
- wheel radius: 0.05 m

Nav2 inputs:
- /map
- /odometry/filtered
- /scan_localization

Nav2 output:
- /cmd_vel_nav

Initial footprint:
- [[0.15, 0.15], [0.15, -0.15], [-0.15, -0.15], [-0.15, 0.15]]

Initial conservative motion limits:
- max_vel_x: 0.6
- min_vel_x: 0.0
- max_vel_theta: 0.8
- acc_lim_x: 0.8
- acc_lim_theta: 1.0
- reverse_allowed: false
- xy_goal_tolerance: 0.20
- yaw_goal_tolerance: 0.20
