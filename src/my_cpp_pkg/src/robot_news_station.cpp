#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"
 
class RobotNewsStation : public rclcpp::Node // MODIFY NAME
{
public:
    RobotNewsStation() : Node("RobotNewsStation") // MODIFY NAME
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news_cpp", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(500),
            std::bind(&RobotNewsStation::timerCallback, this)
        );
        RCLCPP_INFO(this->get_logger(), "RObotNews Station CPP created");
    }
 
private:
    int counter = 1;

    rclcpp::TimerBase::SharedPtr timer_;

    void timerCallback(){
        publishNews();
    }
    void publishNews(){
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("Hello ") + std::to_string(counter);
        counter++;
        publisher_->publish(msg);
    }
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStation>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}