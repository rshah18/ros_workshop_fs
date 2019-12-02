#include "ros/ros.h"
#include "demo/mymsg.h"

void callBack(const demo::mymsg:: ConstPtr & msg){
    ROS_INFO("Recieve msg = %d", msg->stamp.sec);
    ROS_INFO("recieve msg = %d", msg->data);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "subscriber_node");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("mytopic", 100, callBack);
  ros::spin();

  return 0;
}
