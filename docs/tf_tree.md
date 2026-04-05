# TF Tree v0.2

## Frozen frame names
- map
- odom
- base_link
- lidar_link
- imu_link
- camera_link

## TF ownership
- map -> odom : slam_toolbox
- odom -> base_link : EKF (robot_localization)
- base_link -> sensor frames : robot_state_publisher

## Description-owned static frames
- base_link -> chassis
- chassis -> lidar_link
- chassis -> imu_link
- chassis -> camera_link

## Notes
- `robot_state_publisher` is the only owner of base-to-sensor TF.
- Localization packages must not publish sensor-frame transforms.
- During current simulation bringup, some Gazebo-bridged topic messages may still use temporary Gazebo-native `frame_id` values such as:
  - `sparkx_car/odom`
  - `sparkx_car/chassis`
  - `sparkx_car/chassis/lidar`
- These message `frame_id` values do not change the TF ownership contract above.
- Frame-id normalization for simulated sensor/odometry messages can be cleaned up later if needed, but the TF source of truth remains the ownership model above.

## Validation status
Validated in sim:
- `robot_state_publisher` launches with `use_sim_time=true`
- static transforms are available for:
  - `base_link -> lidar_link`
  - `base_link -> imu_link`
  - `base_link -> camera_link`
