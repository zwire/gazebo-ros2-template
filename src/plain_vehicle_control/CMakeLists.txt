cmake_minimum_required(VERSION 3.8)
project(plain_vehicle_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(TARGET_NAME exe)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(
  ${TARGET_NAME}
    src/main.cpp 
    src/effort_node.cpp
)
ament_target_dependencies(
  ${TARGET_NAME}
    rclcpp
    rclcpp_action
    std_msgs
)
install(
  TARGETS 
    ${TARGET_NAME}
  DESTINATION 
    lib/${PROJECT_NAME}
)

install(
  DIRECTORY
    urdf
    launch
    worlds
    config
  DESTINATION 
    share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
