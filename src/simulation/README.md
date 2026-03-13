# Simulation Package

## Overview
This package provides simulation support for the autonomous racing stack (Phase 2 of the roadmap).

**Current Capabilities:**
- Gazebo simulator integration
- ROS 2 - Gazebo bridge for sensor data
- Simple racecar model with LiDAR sensor
- Empty racing track world

## Directory Structure

```
simulation/
├── CMakeLists.txt          # Build configuration
├── package.xml             # Package metadata
├── launch/
│   └── racing_sim.launch.py  # Main simulation launch file
├── worlds/
│   └── empty_racing_track.sdf  # Gazebo world file
└── models/
    └── racecar.sdf           # Racecar model definition
```

## Usage

### Build
```bash
cd ~/colcon_ws
colcon build --packages-select simulation --symlink-install
source install/setup.bash
```

### Launch Simulation
```bash
ros2 launch simulation racing_sim.launch.py
```

This will:
1. Start Gazebo server with the racing track
2. Start Gazebo GUI client
3. Spawn the racecar at origin (0, 0, 0.1)
4. Bridge LiDAR sensor data to ROS 2 topic `/lidar`

### Verify LiDAR Data
In another terminal:
```bash
source install/setup.bash
ros2 topic echo /lidar
```

Or visualize in RViz2:
```bash
rviz2
# Add display: LaserScan topic: /lidar
```

## Phase 2 Progress

Following the Autonomous Racing Stack Roadmap:

- ✅ **Gazebo Setup**: Installed and configured
- ✅ **ROS-Gazebo Bridge**: ros_gz_bridge for topic bridging
- ✅ **Simple World**: Empty racing track for testing
- ✅ **Vehicle Model**: Racecar with LiDAR sensor
- ✅ **Launch System**: Python-based launch files

## Next Steps (Phase 3 onwards)

- Add sensor drivers (Phase 3)
  - Real LiDAR driver nodes
  - Camera drivers
  - IMU and GPS drivers
  
- Add perception (Phase 5)
  - Cone detection from LiDAR
  - Obstacle detection
  
- Add localization (Phase 6)
  - Odometry estimation
  - EKF-based localization
  
- Add planning & control (Phases 7-8)
  - Path planner node
  - Control node
  
- Add visualization (Phase 4)
  - RViz2 configuration
  - TF frame setup

## Common Issues

**Q: Gazebo doesn't start**
```bash
# Check Gazebo installation
which gz
# Should print path to gz executable
```

**Q: LiDAR data not appearing**
```bash
# Verify bridge is running
ros2 topic list | grep lidar
# Should show: /lidar
```

**Q: "World file not found"**
- Ensure `colcon build --symlink-install` was run
- Check that worlds/ and models/ directories exist in install/

## References

- ROS 2 Humble: https://docs.ros.org/en/humble/
- Gazebo Sim: https://gazebosim.org/
- ros_gz_bridge: https://github.com/gazebosim/ros_gz_bridge
