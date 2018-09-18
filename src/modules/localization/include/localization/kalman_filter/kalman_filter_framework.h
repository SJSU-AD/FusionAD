#ifndef KALMAN_FILTER_FRAMEWORK_H
#define KALMAN_FILTER_FRAMEWORK_H

#include "Eigen/Dense"

class KalmanFilter {
    public:
        VectorXd nominal_state;
        MatrixXd cur_covariance;
        void step_once();
    private:
        VectorXd pred_nominal_state;
        MatrixXd pred_covariance;
        MatrixXd proccess_noise; //R
        MatrixXd sensor_noise; //Q
        MatrixXd A; 
        MatrixXd B;
        MatrixXd C;
        void prediction_update(VectorXd &);
        MatrixXd calc_kalman_gain();
        void measurement_update(VectorXd &);
};

#endif