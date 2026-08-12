#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

using namespace example_interfaces::msg;
class NumberCounter: public rclcpp::Node // MODIFY NAME
{
public:
    NumberCounter() : Node("number_counter") // MODIFY NAME
    {
        publisher_= this->create_publisher<Int64>("number_count", 10);
        subscriber_ = this->create_subscription<Int64>
        (
            "number", 10,
            std::bind(
                &NumberCounter::callbackNumber,
                this,
                std::placeholders::_1
            )
        );
        RCLCPP_INFO(this->get_logger(), "Number counter created");
    }
 
private:
    rclcpp::Subscription<Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<Int64>::SharedPtr publisher_;
    int ctr = 0;
    void callbackNumber(const Int64::SharedPtr){
        ctr++;
        auto out = Int64();
        out.data = ctr;
        publisher_->publish(out);
    }
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounter>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}