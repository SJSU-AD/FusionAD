#!/usr/bin/env python

# Copyright 2017 Open Source Robotics Foundation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


import rospy
from interface.msg import Controlcmd
from sensor_msgs.msg import Joy
from std_msgs.msg import Bool


STEERING_AXIS = 0
THROTTLE_AXIS = 4

#obstacle_detected = false

class Translator:
    def __init__(self):
        self.sub = rospy.Subscriber("joy", Joy, self.callback)
        #self.obs_sub = rospy.Subscriber("/localization/obstacle", Bool, self.lidar_cb)
        self.pub = rospy.Publisher('/control/controlcmd', Controlcmd, queue_size=1)
        self.last_published_time = rospy.get_rostime()
        self.last_published = None
        self.timer = rospy.Timer(rospy.Duration(1./20.), self.timer_callback)
        
    def timer_callback(self, event):
        if self.last_published and self.last_published_time < rospy.get_rostime() + rospy.Duration(1.0/20.):
            self.callback(self.last_published)

    def callback(self, message):
        rospy.logdebug("joy_translater received axes %s",message.axes)
        command = Controlcmd()
        command.header = message.header
        global obstacle_detected
        if message.axes[THROTTLE_AXIS] >= 0:
            command.throttle = message.axes[THROTTLE_AXIS] * 100
            #command.brake = 0.0
        else:
            #command.brake = message.axes[THROTTLE_AXIS] * -1
            command.throttle = message.axes[THROTTLE_AXIS] * 100
        #Brake not needed for red car

        #if message.buttons[3]:
        #    command.shift_gears = Control.FORWARD
        #elif message.buttons[1]:
        #    command.shift_gears = Control.NEUTRAL
        #elif message.buttons[0]:
        #    command.shift_gears = Control.REVERSE
        #else:
        #    command.shift_gears = Control.NO_COMMAND
        if abs(message.axes[STEERING_AXIS]) < 0.03:
            command.steeringAngle = 0
        else:
            command.steeringAngle = message.axes[STEERING_AXIS] * 0.33
        self.last_published = message
        self.pub.publish(command)
    
   # def lidar_cb(self, message):
    #    global obstacle_detected

        

if __name__ == '__main__':
    rospy.init_node('joy_translator')
    t = Translator()
    rospy.spin()