#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        super().__init__("py_test")
        
        self.get_logger().info("Hello world")
        self.create_timer(1.0, self.timer_callback) # pass the reference to the function
        self.ctr = 1
        
    def timer_callback(self):
        self.get_logger().info("Hello" + " " + str(self.ctr))
        self.ctr += 1

def main(args = None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node) # this will allow the node to prcoess any callback
    # callback seems to be triggered only when node is spinning
    rclpy.shutdown()
    
    
if __name__ == "__main__":
    main()