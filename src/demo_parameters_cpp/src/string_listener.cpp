#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class Listener : public rclcpp::Node
{
public:
    Listener() : Node("string_listener")
    {
        subscroption = this->create_subscription<std_msgs::msg::String>("string_topic", 10, std::bind(&Listener::callback, this, _1));
    }

private:
    void callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        // RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
        std::cout << "I heard : " << msg->data << std::endl;
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscroption;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Listener>());
    rclcpp::shutdown();
    return 0;
}