#!/usr/bin/env python
import rospy
from demo.msg import mymsg

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %d, %s",data.age, data.name)

def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber("chatter", mymsg, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
