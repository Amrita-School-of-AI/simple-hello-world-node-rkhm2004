#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

// 1. Define the class inheriting from rclcpp::Node
class HelloNode : public rclcpp::Node
{
public:
  HelloNode() : Node("hello_world_node") // 2. Name the node
  {
    // 3. Initialize the timer (1000ms = 1 second)
    timer_ = this->create_wall_timer(
      1000ms, 
      std::bind(&HelloNode::timer_callback, this));
  }

private:
  // 4. Define the callback function
  void timer_callback()
  {
    RCLCPP_INFO(this->get_logger(), "Hello, World!");
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}
