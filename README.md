# ros2-lessons
Udemy Course


### ros2 command line

- `ros2 run [package_name] [executable name]` - run the node defined inside the executable
    - `ros2 run [package_name] [executable name] --ros_args [-r|--remap] __node:=abc` - renames the node ran by executable to the name `abc`
    - `ros2 run [package_name] [executable name] --ros_args [-r |--remap] [topic_name]:=abc` - renames the topic created by executable to the name `abc`.
- `ros2 run -h` - ask for help
- `ros2 node list` - see all nodes currently running
- `ros2 node info` - see publishers, subscribers, service servers

- `rqt` - open a GUI for node introspection

- 

### interfaces
- `ros2 interface show example_interfaces/msg/string` - show the data structure of the asynchronous communication
- `ros2 topic info [topic_name]` - shows the data type, publisher count, subscriber count of a topic. you can then do
    - `ros2 interface show [data type name]` - to see the data type
    you can create any publisher / subscriber for this topic now!

Suppose the data type is
```
jon@jon-5070ti-pc:~/Code/transcelestial/ros2-lessons$ ros2 interface show ge│^C[INFO] [1786501113.427892893] [rclcpp]: signal_handler(SIGINT/SIGTERM)
ometry_msgs/msg/Twist                                                       │jon@jon-5070ti-pc:~/Code/transcelestial/ros2-lessons$ rqt
# This expresses velocity in free space broken into its linear and angular p│
arts.                                                                       │
                                                                            │
Vector3  linear                                                             │
        float64 x                                                           │
        float64 y                                                           │
        float64 z                                                           │
Vector3  angular                                                            │
        float64 x                                                           │
        float64 y                                                           │
        float64 z  
```

Then we can make a publisher

```
ros2 topic pub -r 2 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 1.0}}"
```
We should see this:
```
publishing #156: geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=1.0, y=0.0, z=0.0), angular=geometry_msgs.msg.Vector3(x=0.0, y=0.0, z=1.0)) 

publishing #157: geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=1.0, y=0.0, z=0.0), angular=geometry_msgs.msg.Vector3(x=0.0, y=0.0, z=1.0)) 
...
```
