#include <vector>
#include <rclcpp/rclcpp.hpp>
#include "rclcpp_components/register_node_macro.hpp"
#include "plain_vehicle_control/effort_node.hpp"

namespace plain_vehicle_control
{

EffortNode::EffortNode(
  const rclcpp::NodeOptions& options
) : EffortNode("", options){}

EffortNode::EffortNode(
  const std::string& name_space, 
  const rclcpp::NodeOptions& options
) : Node("effort_node", name_space, options)
{
  using namespace std::chrono_literals;
  pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/effort_controllers/commands", rclcpp::QoS(10));
  timer_ = this->create_wall_timer(100ms,
    [this]()->void 
    {
      auto msg = std::make_shared<std_msgs::msg::Float64MultiArray>();
      msg->data.push_back(1);
      msg->data.push_back(1);
      RCLCPP_INFO(this->get_logger(), "Pub: effort: L: %f, R: %f", msg->data[0], msg->data[1]);
      pub_->publish(*msg);
    }
  );
}

}

RCLCPP_COMPONENTS_REGISTER_NODE(plain_vehicle_control::EffortNode)