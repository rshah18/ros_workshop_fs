#!/usr/bin/env python

from demo.srv import services, servicesResponse
import rospy

def handle_add_two_ints(req):
    a = rospy.get_param('op')
    if a == 'sub':
        return servicesResponse(req.a - req.b)
    elif a == 'add':
        return servicesResponse(req.a + req.b)
    elif a == 'mult':
        return servicesResponse(req.a * req.b)


def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    rospy.set_param('op', 'add')
    s = rospy.Service('add_two_ints', services, handle_add_two_ints)
    print("Ready to operate on two ints.")
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()
