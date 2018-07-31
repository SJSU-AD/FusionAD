#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64

negative_trigger = 0 # trigger when the slope is negative (negative == 1, positive == 0)
point_density = 10000 # how many points between each interpolated point?

X_Position = [] # declaring the lists for data input
Y_Position = [] 
x_interpolated_position = [] # declaring the lists for interpolated positions
y_interpolated_position = []
vector_size = len(X_Position) # finding the length of the x_position list

i = 0

def interpolation_function():
    x_publisher = rospy.Publisher('interpolation_x', Float64, queue_size = 10) # declaring publisher for interpolation_x topic
    y_publisher = rospy.Publisher('interpolation_y', Float64, queue_size=10) # declaring publisher for interpolation_y topic
    rospy.init_node('interpolation_node', anonymous = True) # declaring interpolation node
    rate = rospy.Rate(100) # 1 Hz publish

    while not rospy.is_shutdown():
        while i <= vector_size-2:
            x_0 = X_Position[i] # declaring the first x-position for interpolation
            x_1 = X_Position[i+1] # declaring the second x-position for interpolation
            y_0 = Y_Position[i] # declaring the first y-position for interpolation
            y_1 = Y_Position[i+1] # declaring the second y-position for interpolation

            if y_1 < y_0: # finding the slope of the desired points
                negative_trigger = 1 # negative slope
            elif y_1 >= y_0:
                negative_trigger = 0 # positive slope
                
            if negative_trigger == 1: # when the slope is negative
                for a in range (0,point_density):
                    if a == 0:
                        y_break[a] = y_0 # initial y_position
                        x_break[a] = x_0 # initial x_position
                    elif a > 0:
                        y_break[a] = y_0-(y_0-y_1)*a/point_density # interpolate with the given point density
                        x_break[a] = x_0-(x_0-x_1)*a/point_density

            elif negative_trigger == 0: # when the slope is positive
                for a in range (0,point_density):
                    if a == 0:
                        y_break[a] = y_0 # initial y_position
                        x_break[a] = x_0 # initial x_position
                    elif a > 0:
                        y_break[a] = y_0+(y_1-y_0)*a/point_density # interpolate with the given point density
                        x_break[a] = x_0+(x_1-x_0)*a/point_density

            y_interpolated_position.append(y_break) # append to each of the interpolated lists
            x_interpolated_position.append(x_break)

        for c in range (0,len(y_interpolated_position)):
            y_publisher.publish(y_interpolated_position[c]) # publish each of the interpolated lists
            x_publisher.publish(x_interpolated_position[c])
            print(x_interpolated_position[c])
            rate.sleep()


if __name__ == '__main__':
    try:
        interpolation_function()
    except rospy.ROSInterruptException:
        pass






