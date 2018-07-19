#!/usr/bin/env python

"""Find the lane offset of a vehicle, assuming camera is in middle of car"""

import numpy as np
import cv2
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import pickle
from combined_thresh import combined_thresh
from perspective_transform import perspective_transform
from Line import Line
from line_fit import line_fit, tune_fit, final_viz, calc_curve, calc_vehicle_offset

# Global variables (just to make the moviepy video annotation work)
with open('calibrate_camera.p', 'rb') as f:
	save_dict = pickle.load(f)
mtx = save_dict['mtx']
dist = save_dict['dist']
window_size = 5  # how many frames for line smoothing
left_line = Line(n=window_size)
right_line = Line(n=window_size)
detected = False  # did the fast line fit detect the lines?
left_curve, right_curve = 0., 0.  # radius of curvature for left and right lanes
left_lane_inds, right_lane_inds = None, None  # for calculating curvature

def get_offset(img_in):
	"""
	Annotate the input image with lane line markings
	Returns annotated image
	"""
	global mtx, dist, left_line, right_line, detected
	global left_curve, right_curve, left_lane_inds, right_lane_inds

	# Undistort, threshold, perspective transform
	undist = cv2.undistort(img_in, mtx, dist, None, mtx)
	img, abs_bin, mag_bin, dir_bin, hls_bin = combined_thresh(undist)
	binary_warped, binary_unwarped, m, m_inv = perspective_transform(img)

	# Perform polynomial fit
	if not detected:
		# Slow line fit
		ret = line_fit(binary_warped)
		left_fit = ret['left_fit']
		right_fit = ret['right_fit']
		nonzerox = ret['nonzerox']
		nonzeroy = ret['nonzeroy']
		left_lane_inds = ret['left_lane_inds']
		right_lane_inds = ret['right_lane_inds']

		# Get moving average of line fit coefficients
		left_fit = left_line.add_fit(left_fit)
		right_fit = right_line.add_fit(right_fit)

		# Calculate curvature
		left_curve, right_curve = calc_curve(left_lane_inds, right_lane_inds, nonzerox, nonzeroy)

		detected = True  # slow line fit always detects the line

	else:  # implies detected == True
		# Fast line fit
		left_fit = left_line.get_fit()
		right_fit = right_line.get_fit()
		ret = tune_fit(binary_warped, left_fit, right_fit)
		left_fit = ret['left_fit']
		right_fit = ret['right_fit']
		nonzerox = ret['nonzerox']
		nonzeroy = ret['nonzeroy']
		left_lane_inds = ret['left_lane_inds']
		right_lane_inds = ret['right_lane_inds']

		# Only make updates if we detected lines in current frame
		if ret is not None:
			left_fit = ret['left_fit']
			right_fit = ret['right_fit']
			nonzerox = ret['nonzerox']
			nonzeroy = ret['nonzeroy']
			left_lane_inds = ret['left_lane_inds']
			right_lane_inds = ret['right_lane_inds']

			left_fit = left_line.add_fit(left_fit)
			right_fit = right_line.add_fit(right_fit)
			left_curve, right_curve = calc_curve(left_lane_inds, right_lane_inds, nonzerox, nonzeroy)
		else:
			detected = False

	vehicle_offset = calc_vehicle_offset(undist, left_fit, right_fit)

	return vehicle_offset

if __name__ == "__main__":
	# cap = cv2.VideoCapture('project_video.mp4')

	# while(True):
	# 	# Capture frame-by-frame
	# 	ret, frame = cap.read()
	# 	# img = mpimg.imread(frame)

	# 	print(get_offset(frame))

	# 	# Display the resulting frame
	# 	cv2.imshow('original', frame)
	# 	if cv2.waitKey(1) & 0xFF == ord('q'):
	# 		break

	# # When everything done, release the capture
	# cap.release()
	# cv2.destroyAllWindows()


    # Show example annotated image on screen for sanity check
	img_file = 'test_images/test2.jpg'
	img = mpimg.imread(img_file)
	result = get_offset(img)
	# result = get_offset(img)
	# result = get_offset(img)
	plt.imshow(result)
	plt.show()