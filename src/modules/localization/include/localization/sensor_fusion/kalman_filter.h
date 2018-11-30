#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#include "Eigen/Dense"

namespace fusionad
{
namespace localization
{

class KalmanFilter {
public:
    // state vector
    Eigen::VectorXd x_;

    // state covariance matrix
    Eigen::MatrixXd P_;

    // state transistion matrix
    Eigen::MatrixXd F_;

    // control matrix
    Eigen::MatrixXd B_;

    // process covariance matrix
    Eigen::MatrixXd Q_;

    // measurement matrix
    Eigen::MatrixXd H_;

    // measurement covariance matrix
    Eigen::MatrixXd R_;

    /**
     * Constructor
     */
    KalmanFilter();

    /**
     * Destructor
     */
    virtual ~KalmanFilter();

    /**
     * Init Initializes Kalman filter
     * @param x_in Initial state
     * @param P_in Initial state covariance
     * @param F_in Transition matrix
     * @param B_in Control matrix
     * @param H_in Measurement matrix
     * @param R_in Measurement covariance matrix
     * @param Q_in Process covariance matrix
     */
    void Init(Eigen::VectorXd &x_in, Eigen::MatrixXd &P_in, 
        Eigen::MatrixXd &F_in, Eigen::MatrixXd & B_in, 
        Eigen::MatrixXd &H_in, Eigen::MatrixXd &R_in, Eigen::MatrixXd &Q_in);

    /**
    * Prediction Predicts the state and the state covariance
    * using the process model
    * @param u_in Control input
    */
    void Predict(const VectorXd & u_in);

    /**
    * Updates the state by using standard Kalman Filter equations
    * @param z The measurement at k+1
    */
    void Update(const Eigen::VectorXd &z);

};

}
}

#endif