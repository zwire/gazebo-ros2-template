cmake_minimum_required(VERSION 3.8)
project(tricycle_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)

add_library(control_node src/control_node.cpp)
target_compile_features(control_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(control_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  control_node
  "rclcpp"
  "rclcpp_components"
  "rclcpp_action"
  "std_msgs"
)

# add a postscript
rclcpp_components_register_node(
  control_node
  PLUGIN "tricycle_control::ControlNode"
  EXECUTABLE exe
)

target_compile_definitions(control_node PRIVATE "TRICYCLE_CONTROL_BUILDING_LIBRARY")

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS control_node
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# add a postscript
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

ament_export_include_directories(
  include
)
ament_export_libraries(
  control_node
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_package()
