#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64_multi_array.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
    Talker() : Node("int_array_talker"), count(0)
    {
        std::vector<int64_t> defalt_int_array = {1,2,3};
        int_array_param = this->declare_parameter("int_array_param", defalt_int_array);

        int_array_pub = this->create_publisher<std_msgs::msg::Int64MultiArray>("int_array_topic", 10);
        timer = this->create_wall_timer(500ms, std::bind(&Talker::timer_callback, this));
    }

private:
    void timer_callback()
    {
        update_parameters();
        auto int_array_msg = std_msgs::msg::Int64MultiArray();
        int_array_msg.data = int_array_param;
        std::string str = "";
        for(size_t i=0; i < int_array_msg.data.size(); i++)
        {
            if(i < int_array_msg.data.size() - 1)
            {
                str += std::to_string(int_array_msg.data.at(i)) + ", ";
            }
            else
            {
                str += std::to_string(int_array_msg.data.at(i));
            }
        }
        RCLCPP_INFO(this->get_logger(), "publishing : '[%s]'", str.c_str());
        int_array_pub->publish(int_array_msg);
    }

    void update_parameters()
    {
        this->get_parameter("int_array_param", int_array_param);
    }

    std::vector<int64_t> int_array_param;
    rclcpp::Publisher<std_msgs::msg::Int64MultiArray>::SharedPtr int_array_pub;

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