# TF Tree v0.1

## Frozen frame names
- map
- odom
- base_link
- lidar_link
- imu_link
- camera_link

## Ownership
- map -> odom : slam_toolbox
- odom -> base_link : EKF (robot_localization)
- base_link -> sensor frames : robot_state_publisher
