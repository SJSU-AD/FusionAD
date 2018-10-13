#include <gtest/gtest.h>
#include <control/lat_controller.h>
#include <control/control_node.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include "Eigen/Dense"

// Include the path
#include <test_data_and_doc/path.h>

using namespace std;



// TEST CASE 1: Arithmatic test for algorithm, refer to "unittest_cases.pdf" in the folder
//  ArimthMatic test case 1
TEST(arithmatic_test_1, ShouldPass)
{
  vector<float> pathX(pathArrayX, pathArrayX + sizeof(pathArrayX)/sizeof(pathArrayX[0]));
  vector<float> pathY(pathArrayY, pathArrayY + sizeof(pathArrayY)/sizeof(pathArrayY[0]));

  // Set the position of the vehical at (-1, -1)
  Eigen::Vector2f veh_pos(-1,-1);

  float veh_theta = 1.5708;
  float veh_velocity = 1.2;

  int wpIndex = 1;

  float k_hard = 15;

  ASSERT_EQ(pathX.size() , pathY.size());

  size_t path_size = pathX.size();

  computed_steering = computeSteeringAngle(veh_pos, pathX, pathY,
                                           veh_velocity, wpIndex,
                                           veh_theta, k_hard, path_size);
  //ASSERT_EQ(computed_steering, tc1_solution);

}




int main(int argc, char **argv) {
    //k_soft is implicitly set to zero, algorithm does not account for k soft
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}