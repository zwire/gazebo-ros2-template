// _kbhit
// https://github.com/nek009/key_event
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// ASCII code map
// https://www.k-cube.co.jp/wakaba/server/ascii_code.html

#include <vector>
#include <rclcpp/rclcpp.hpp>
#include "rclcpp_components/register_node_macro.hpp"
#include "tricycle_control/control_node.hpp"

namespace tricycle_control
{
    
ControlNode::ControlNode(
  const rclcpp::NodeOptions& options
) : ControlNode("", options){}

ControlNode::ControlNode(
  const std::string& name_space, 
  const rclcpp::NodeOptions& options
) : Node("control_node", name_space, options)
{
  using namespace std::chrono_literals;
  _position_pub = this->create_publisher<std_msgs::msg::Float64MultiArray>("/position_controllers/commands", rclcpp::QoS(10));
  _effort_pub = this->create_publisher<std_msgs::msg::Float64MultiArray>("/effort_controllers/commands", rclcpp::QoS(10));
  _timer = this->create_wall_timer(50ms,
    [this]()->void 
    {
      if(_kbhit())
      {
        auto key = getchar();
        switch (key)
        {
          case 97:  // a
            _steer -= 1;
            break;
          case 100: // d
            _steer += 1;
            break;
          case 120: // x
            _accel -= 0.2;
            break;
          case 119: // w
            _accel += 0.2;
            break;
          case 115: // s
            _steer = 0;
            _accel = 0;
            break;
          default:
            return;
        }
        auto position = std::make_shared<std_msgs::msg::Float64MultiArray>();
        position->data.push_back(_steer * M_PI / 180);
        auto effort = std::make_shared<std_msgs::msg::Float64MultiArray>();
        effort->data.push_back(_accel * -1);
        effort->data.push_back(_accel * -1);
        RCLCPP_INFO(this->get_logger(), "steer: %.1f, accel: %.1f", _steer, _accel);
        _position_pub->publish(*position);
        _effort_pub->publish(*effort);
      }
    }
  );
}

int ControlNode::_kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

}

RCLCPP_COMPONENTS_REGISTER_NODE(tricycle_control::ControlNode)