cmake_minimum_required(VERSION 3.5)
project(demo_parameters_cpp)

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

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include)

rosidl_generate_interfaces(${PROJECT_NAME}
    "msg/BoolMultiArray.msg"
    "msg/StringMultiArray.msg"
    DEPENDENCIES std_msgs
)

add_executable(string_talker src/string_talker.cpp)
ament_target_dependencies(string_talker
    rclcpp
    std_msgs
)
rosidl_target_interfaces(string_talker ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(string_listener src/string_listener.cpp)
ament_target_dependencies(string_listener
    rclcpp
    std_msgs
)

add_executable(int_array_talker src/int_array_talker.cpp)
ament_target_dependencies(int_array_talker
    rclcpp
    std_msgs
)

add_executable(int_array_listener src/int_array_listener.cpp)
ament_target_dependencies(int_array_listener
    rclcpp
    std_msgs
)

install(TARGETS
    string_talker
    string_listener
    int_array_talker
    int_array_listener
    DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
    DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY parameters
    DESTINATION share/${PROJECT_NAME}
)

ament_package()
