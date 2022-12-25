#ifndef PLAIN_VEHICLE_CONTROL__EFFORT_NODE_HPP_
#define PLAIN_VEHICLE_CONTROL__EFFORT_NODE_HPP_

#include <std_msgs/msg/float64_multi_array.hpp>
#include <rclcpp/rclcpp.hpp>
#include "plain_vehicle_control/visibility_control.h"

namespace plain_vehicle_control
{

class EffortNode : public rclcpp::Node
{
private:
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  int count_;
public:
  PLAIN_VEHICLE_CONTROL_PUBLIC
  EffortNode(
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
  PLAIN_VEHICLE_CONTROL_PUBLIC
  EffortNode(
    const std::string& name_space, 
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
};

}

#endif
