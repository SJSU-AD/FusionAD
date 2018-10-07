#include <gtest/gtest.h>
#include <control/lat_controller.h>
#include <control/control_node.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <limits>

TEST(path_heading_test_m_1, ShouldPass){
  fusionad::control::lat_controller::stanley stanley_test;
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
  


  // TODO: Insert answer
  ASSERT_EQ( 1 , stanley_test.computePathHeading(path_x, path_y, target_point, path_size));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}