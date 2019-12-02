#!/usr/bin/env python
from __future__ import print_function
import rospy
import actionlib
import demo.msg
import sys 

def fibonacci_client():
    print("client called")
    client = actionlib.SimpleActionClient('Fibonacci', demo.msg.fibAction)
    print("waiting for server")
    client.wait_for_server()
    
    goal = demo.msg.fibGoal(order = 20)
    client.send_goal(goal)
    print("goal send")
    client.wait_for_result()
    print("waiting for result")
    return client.get_result()

if __name__ == '__main__':
    try:
        rospy.init_node('fibonacci_client')
        result = fibonacci_client()
        for n in result.sequence:
            print(str(n))
    except rospy.ROSInterruptException:
        print("Program interrupted before completion", file=sys.stderr)
