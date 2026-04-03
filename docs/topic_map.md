# Topic Map v0.1

## Command chain
- /cmd_vel_nav -> navigation output
- /cmd_vel_smoothed -> control output
- /cmd_vel -> final command after safety gating

## Status / feedback
- /vehicle_status -> STM32 / vehicle state feedback
- /bridge_status -> bridge health / comms status
- /wheel_odom -> wheel odometry feedback

## Sensors
- /scan
- /image_raw
- /imu/data
- /fix

## Localization / mapping
- /odometry/filtered
- /map
- /tf
- /tf_static
