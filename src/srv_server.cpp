#include<iostream>
#include "ros/ros.h"
#include "demo/services.h"
using namespace std;

bool calculation(demo::services::Request &req, demo::services::Response &res){
  res.result = req.a + req.b;

  cout << "request: "<< req.a << " " << req.b << endl;
  cout << "response: " << res.result << endl;
  return true;
}

int main(int argc, char **argv){

  ros::init(argc, argv, "Service_server");
  ros::NodeHandle nh;
  ros::ServiceServer srv_server = nh.advertiseService("cal_srv", calculation);

  ROS_INFO("ready calculation service: cal_srv");

  ros::spin(); // wait for service request

  return 0;
}
