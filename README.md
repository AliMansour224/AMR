# SparkX

ROS 2 Jazzy autonomy workspace for SparkX v1.

## Current baseline
Active Phase 0 baseline includes:
- interfaces
- bridge
- bringup
- description
- simulation
- localization
- navigation
- control
- safety
- sensor_drivers

## Architecture direction
- ROS 2 Jazzy on Ubuntu 24.04
- Jetson runs ROS graph
- STM32 handles low-level safety and execution
- CAN is the intended vehicle-controller path
- command chain:
  - /cmd_vel_nav
  - /cmd_vel_smoothed
  - /cmd_vel

## Workspace structure
- `src/`
- `docker/`
- `docs/`
- `firmware/`
- `tools/`

## Notes
Some old code from previous planning phases may still exist in the repo, but the current active baseline is the new Phase 0 architecture.
