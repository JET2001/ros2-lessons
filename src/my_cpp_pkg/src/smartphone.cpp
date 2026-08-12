#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"
class SmartphoneNode : public rclcpp::Node // MODIFY NAME
{
public:
    SmartphoneNode() : Node("smartphone") // MODIFY NAME
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::String>(
            "robot_news", 10, 
            std::bind(
                &SmartphoneNode::callbackRobotNewsCPP, // callback
                this, // bind to this object
                std::placeholders::_1 // placeholders for the number of arguments
                //std::palceholders::_2 --> placeholder for second argument if necessary
            )
        );
        RCLCPP_INFO(this->get_logger(), "Smartphone has been started");
    }
 
private:
    void callbackRobotNewsCPP( const example_interfaces::msg::String::SharedPtr msg){
        RCLCPP_INFO(this->get_logger(), (std::string("Received: ") + msg->data).c_str());
    }
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;

};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartphoneNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}