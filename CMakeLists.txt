cmake_minimum_required(VERSION 3.8)
project(ros2_hello_world)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Define the executable and its source file
add_executable(hello_node src/hello_node.cpp)

# Link the rclcpp library
ament_target_dependencies(hello_node rclcpp)

# Install the node so 'ros2 run' can find it later
install(TARGETS
  hello_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
