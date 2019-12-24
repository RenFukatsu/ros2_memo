#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64_multi_array.hpp"

using std::placeholders::_1;

class Listener : public rclcpp::Node
{
public:
    Listener() : Node("int_array_listener")
    {
        subscroption = this->create_subscription<std_msgs::msg::Int64MultiArray>("int_array_topic", 10, std::bind(&Listener::callback, this, _1));
    }

private:
    void callback(const std_msgs::msg::Int64MultiArray::SharedPtr msg) const
    {
        std::string str = "";
        for(size_t i=0; i < msg->data.size(); i++)
        {
            if(i < msg->data.size() - 1)
            {
                str += std::to_string(msg->data.at(i)) + ", ";
            }
            else
            {
                str += std::to_string(msg->data.at(i));
            }
        }
        RCLCPP_INFO(this->get_logger(), "I heard: '[%s]'", str.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::Int64MultiArray>::SharedPtr subscroption;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Listener>());
    rclcpp::shutdown();
    return 0;
}