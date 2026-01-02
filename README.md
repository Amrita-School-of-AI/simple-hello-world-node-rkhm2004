[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/sDhqHZ0-)
# Assignment: ROS2 C++ Hello World

**Course:** ROS2 Fundamentals  
**Build System:** ament_cmake

## Objective
The goal of this assignment is to verify your understanding of:
1. The structure of a ROS2 C++ package.
2. How to create a basic `rclcpp::Node`.
3. How to use `ament_cmake` to compile a ROS2 node.

## Problem Statement
You must complete the provided skeleton code to create a ROS2 node that simply logs the message **"Hello, World!"** to the console once every second.

### Requirements
1. **Source Code (`src/hello_node.cpp`)**:
    - Implement a class `HelloNode` that inherits from `rclcpp::Node`.
    - Initialize the node with the name `"hello_world_node"`.
    - Create a timer that fires every **1000ms**.
    - Inside the timer callback, use `RCLCPP_INFO` to print `"Hello, World!"`.

2. **Build Configuration (`CMakeLists.txt`)**:
    - Add an executable target named `hello_node` compiled from `src/hello_node.cpp`.
    - Link the `rclcpp` dependencies using `ament_target_dependencies`.
    - Ensure the executable is installed to `lib/${PROJECT_NAME}`.

3. **Package Metadata (`package.xml`)**:
    - Add the missing dependency tag for `rclcpp`.

## How to Test Locally
Before pushing to GitHub, ensure your code runs locally:

```bash
# 1. Build the package
colcon build --packages-select ros2_hello_world

# 2. Source the setup file
source install/setup.bash

# 3. Run the node
ros2 run ros2_hello_world hello_node

#### Expected Output:

```shell
[INFO] [1700000000.123456789] [hello_world_node]: Hello, World!
[INFO] [1700000001.123456789] [hello_world_node]: Hello, World!
...
```
