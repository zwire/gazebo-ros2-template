#ifndef EFFORT_NODE_HPP_
#define EFFORT_NODE_HPP_

#include <std_msgs/msg/float64_multi_array.hpp>
#include <rclcpp/rclcpp.hpp>

class EffortNode : public rclcpp::Node
{
private:
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  int count_;
public:
  EffortNode(
    const std::string& name_space = "", 
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
};

#endif