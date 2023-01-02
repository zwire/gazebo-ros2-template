#ifndef TRICYCLE_CONTROL__CONTROL_NODE_HPP_
#define TRICYCLE_CONTROL__CONTROL_NODE_HPP_

#include <std_msgs/msg/float64_multi_array.hpp>
#include <rclcpp/rclcpp.hpp>
#include "tricycle_control/visibility_control.h"

namespace tricycle_control
{

class ControlNode : public rclcpp::Node
{
  
private:
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr _position_pub;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr _effort_pub;
  rclcpp::TimerBase::SharedPtr _timer;
  double _steer;
  double _accel;
  int _kbhit(void);
public:
  TRICYCLE_CONTROL_PUBLIC
  ControlNode(
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
  TRICYCLE_CONTROL_PUBLIC
  ControlNode(
    const std::string& name_space, 
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
};

}

#endif
