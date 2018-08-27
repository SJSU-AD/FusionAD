class KalmanFilter {
    public:
        MatrixXd nominal_state;
        MatrixXd cur_covariance;
        void step_once();
    private:
        MatrixXd pred_nominal_state;
        MatrixXd pred_covariance;
        MatrixXd proccess_noise;
        MatrixXd sensor_noise;
        MatrixXd A;
        MatrixXd B;
        MatrixXd C;
        void prediction_update();
        void calc_kalman_gain();
        void measurement_update();
};