cmake_minimum_required(VERSION 3.5)
project(action_bridge)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(stretch_topological_navigation_msgs REQUIRED)

# find ROS 1 packages
include(cmake/find_ros1_package.cmake)

find_package(PkgConfig REQUIRED)

find_ros1_package(actionlib REQUIRED)
find_ros1_package(move_base_msgs REQUIRED)
find_ros1_package(ori_topological_navigation_msgs REQUIRED)
find_ros1_package(roscpp REQUIRED)

ament_export_include_directories(include)
include_directories(include)

add_executable(action_bridge_move_base_node
    "src/action_bridge_move_base.cpp"
)
ament_target_dependencies(action_bridge_move_base_node
    "ros1_roscpp" "ros1_actionlib" "ros1_move_base_msgs"
    "rclcpp" "rclcpp_action" "nav2_msgs"
)

add_executable(action_bridge_topological_navigation_node
    "src/action_bridge_topological_navigation.cpp"
)
ament_target_dependencies(action_bridge_topological_navigation_node
    "ros1_roscpp" "ros1_actionlib" "ros1_ori_topological_navigation_msgs"
    "rclcpp" "rclcpp_action" "stretch_topological_navigation_msgs"
)

install(TARGETS action_bridge_move_base_node action_bridge_topological_navigation_node
    DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
