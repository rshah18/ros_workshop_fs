#include "ros/ros.h"
#include "demo/mymsg.h"

int main(int argc, char **argv ){

  ros::init(argc, argv, "publisher_node");
  ros::NodeHandle nh; // create a node handle
  ros::Publisher pub = nh.advertise<demo::mymsg>("mytopic", 10);
  ros::Rate loop_rate(10); // frequency of message published in hertz
  demo::mymsg msg;  // a message object

  int count = 0;
  while(ros::ok()){
    msg.stamp = ros::Time::now();
    msg.data = count;
    ROS_INFO("send msg = %d", msg.stamp.sec);
    ROS_INFO("send msg = %d", msg.data);
    pub.publish(msg);
    loop_rate.sleep();
    ++count;
  }
  return 0;
}
