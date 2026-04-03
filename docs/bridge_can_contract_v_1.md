# Bridge / CAN Contract v0.1

## Scope
ROS 2 bridge receives final /cmd_vel and communicates command intent to STM32.
STM32 is the low-level safety authority and sends actuator commands over CAN.

## Command ownership
- Jetson / ROS:
  - navigation
  - control smoothing
  - safety gating
  - final /cmd_vel publication
- STM32:
  - command validation
  - watchdog timeout stop
  - Twist to wheel target conversion
  - CAN transmission to motor controller
  - status / fault reporting

## Inputs to bridge
- /cmd_vel

## Outputs from bridge
- /bridge_status
- /vehicle_status
- /wheel_odom

## v0.1 behavior
- no valid command stream -> safe stop
- timeout on command stream -> safe stop
- invalid command / fault -> reject and report
- estop condition -> zero motion command

## Notes
Exact CAN IDs and payload bytes are defined later with firmware/electrical work.
This doc freezes ownership and behavior first.
