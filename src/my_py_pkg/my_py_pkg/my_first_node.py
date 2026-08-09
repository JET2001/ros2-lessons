#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

def main(args=None):
    rclpy.init(args=args)
    #
    node = Node("py_test") # the node is here, its inside the python file
    node.get_logger().info("Hello world")
    rclpy.spin(node) #keep the node alive until you press CtrlC
    
    #
    rclpy.shutdown()

if __name__ == "__main__":
    main()