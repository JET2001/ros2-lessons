import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

# smartphone listening on the robot_news topic
class SmartphoneNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("smartphone") # MODIFY NAME
        self.subscriber = self.create_subscription(
            String, "robot_news", self.callback_robot_news, 10
        )
        self.get_logger().info("Smartphone node started")
    
    def callback_robot_news(self, msg: String):
        self.get_logger().info("Received: " + msg.data)
        
def main(args=None):
    rclpy.init(args=args)
    node = SmartphoneNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()