#!/usr/bin/env python
import rospy
from demo.msg import mymsg
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('chatter', mymsg, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10)

    msg = mymsg()
    msg.age = 67
    msg.name = "ravi"

    while not rospy.is_shutdown():
        msg.data += 1
        rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
