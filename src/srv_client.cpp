#include<iostream>
#include<cstdlib>
#include "ros/ros.h"
#include "demo/services.h"
using namespace std;

int main(int argc, char **argv){

  ros::init(argc, argv, "Service_client");

  if(argc != 3){
    ROS_INFO("cmd: rosrun demo Service_client arg0 arg1");
    ROS_INFO("arg0: double number, arg1: double number");
    return 1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient srv_client = nh.serviceClient<demo::services>("cal_srv");
  demo::services srv;

  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);

  if(srv_client.call(srv)){
    cout<< "send " << srv.request.a << " "<< srv.request.b << endl;
    cout << "recieve srv, result: "<< srv.response.result << endl;

  } else{
    cout << "failed to call service";
    return 1;
  }

  return 0;
}
