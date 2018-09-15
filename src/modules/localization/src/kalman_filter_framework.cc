#include "segmenter/kalman_filter_framework.h"

void KalmanFilter::prediction_update(VectorXd & control_input) {
    pred_nominal_state = (A * nominal_state) + (B * control_input);
    pred_covariance = ((A * cur_covariance) * A.transpose())) + proccess_noise;
}

void KalmanFilter::calc_kalman_gain() {
    MatrixXd K = (pred_covariance * C.transpose()) * ((C * pred_covariance * C.transpose()) + sensor_noise).inverse();
    return K;
}

void KalmanFilter::measurement_update(VectorXd & measurement) {
    MatrixXd K = calc_kalman_gain();
    nominal_state = pred_nominal_state + (K * (measurement - (C * pred_nominal_state)));
    MatrixXd temp = K * C;
    cur_covariance = (MatrixXd::Identity(temp.cols(), temp.rows()) - temp) * pred_covariance;
}

void KalmanFilter::step_once(VectorXd & control_input, VectorXd & measurement) {
    prediction_update(control_input);
    measurement_update(measurement);
}