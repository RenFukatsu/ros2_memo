#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
    Talker() : Node("string_talker"), count(0)
    {
        string_param = this->declare_parameter("string_param", "defalt");

        string_pub = this->create_publisher<std_msgs::msg::String>("string_topic", 10);
        timer = this->create_wall_timer(500ms, std::bind(&Talker::timer_callback, this));
    }

private:
    void timer_callback()
    {
        update_parameters();
        auto string_msg = std_msgs::msg::String();
        string_msg.data = string_param;
        RCLCPP_INFO(this->get_logger(), "publishing : '%s'", string_msg.data.c_str());
        string_pub->publish(string_msg);
    }

    void update_parameters()
    {
        this->get_parameter("string_param", string_param);
    }

    std::string string_param;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr string_pub;

    rclcpp::TimerBase::SharedPtr timer;
    size_t count;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Talker>());
    rclcpp::shutdown();
    return 0;
}