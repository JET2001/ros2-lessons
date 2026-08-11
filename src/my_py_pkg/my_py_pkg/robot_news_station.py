import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
 
class RobotNewsStationNode(Node): 
    '''
    a node that publishes hello to the topic "robot_news" once every 30 seconds
    '''
    
    def __init__(self):
        super().__init__("robot_news_station")
        self.publisher_ = self.create_publisher(String, "robot_news", 10) # data type, topic name, queue size
        self.ctr = 1
        self.create_timer(0.5, self.timer_callback)
        self.get_logger().info("RobotNewsStation has started")
    
    def publish_news(self):
        msg = String()
        msg.data = "Hello " + str(self.ctr)
        self.publisher_.publish(msg)
        self.ctr += 1
        
    def timer_callback(self):
        self.publish_news()
 
def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()