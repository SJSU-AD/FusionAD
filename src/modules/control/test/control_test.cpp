#include <gtest/gtest.h>
#include <control/lat_controller.h>
#include <control/control_node.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <limits>


// Remove comment for "Private:" in lat_controller.h after testing.

/*
TEST CASE 1:
Testing path heading computation with a path of slope = 1, in the first quadrant
*/
TEST(path_heading_test_m_1, ShouldPass)
{
  // Initialize controller 
  fusionad::control::lat_controller::stanley stanley_test;
  // Set target setpoint to first point
  int target_point = 0;
  std::vector<float> path_x;
  std::vector<float> path_y;
  size_t path_size;

  path_x.clear();
  path_y.clear();

  //Start with path points that are perfectly linear at m = 1;
  for(int i = 0; i < 4; i++)
  {
    path_x.push_back(i);
    path_y.push_back(i);
  }

  ASSERT_TRUE(path_x.size() == path_y.size());
  path_size = path_x.size();
  
  // Correct answer will be the arctangent of 1/1 since the slope of the line should be a straight line of 1
  float correct_ans = std::atan2(1,1);

  ASSERT_EQ(correct_ans, stanley_test.computePathHeading(path_x, path_y, target_point, path_size));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}