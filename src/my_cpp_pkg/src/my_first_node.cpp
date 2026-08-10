#include "rclcpp/rclcpp.hpp"


class MyNode : public rclcpp::Node 
{
public:
    MyNode() : Node("cpp_test"){
        RCLCPP_INFO(this->get_logger(), "Hello World!");
        
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1), 
            std::bind(&MyNode::timer_callback, this)
        );
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    int ctr = 1;

    
    void timer_callback(){
        RCLCPP_INFO(this->get_logger(), "Hello %d", this->ctr);
        (this->ctr)++;
    }
};
int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    // in Cpp, we should create a shared pointer to the node class.
    // for reference, the shared pointer can be referred to by multiple entities.
    // we have multiple pointers that point to the same reference. 
    // maintains an initial reference counter.
    // if the shared pointer is copied, the counter is incremented.
    // the underlying resource is only deleted when the reference counter
    // hits zero.
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}