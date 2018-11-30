#include "localization/kalman_filter.h"

namespace fusionad
{
namespace localization
{

KalmanFilter::KalmanFilter() {}

KalmanFilter::~KalmanFilter() {}

void Init(Eigen::VectorXd &x_in,Eigen::MatrixXd &P_in, 
        Eigen::MatrixXd &F_in, Eigen::MatrixXd & B_in, Eigen::MatrixXd &H_in, 
        Eigen::MatrixXd &R_in, Eigen::MatrixXd &Q_in) {
    x_ = x_in;
    P_ = P_in;
    F_ = F_in;
    B_ = B_in;
    H_ = H_in;
    R_ = R_in;
    Q_ = Q_in;
}

void KalmanFilter::Predict(const Eigen::VectorXd & u_in) {
    x_ = F_ * x_ + B_ * u_in;
    Eigen::MatrixXd Ft = F_.transpose();
    P_ = F_ * P_ * Ft + Q_;
}

void KalmanFilter::Update(const Eigen::VectorXd & z) {
    Eigen::VectorXd z_pred = H_ * x_;

    Eigen::VectorXd y = z - z_pred;
    Eigen::MatrixXd Ht = H_.transpose();
    Eigen::MatrixXd PHt = P_ * Ht;
    Eigen::MatrixXd S = H_ * PHt + R_;
    Eigen::MatrixXd Si = S.inverse();
    Eigen::MatrixXd K = PHt * Si;

    //new estimate
    x_ = x_ + (K * y);
    long x_size = x_.size();
    Eigen::MatrixXd I = Eigen::MatrixXd::Identity(x_size, x_size);
    P_ = (I - K * H_) * P_;
}

}
}