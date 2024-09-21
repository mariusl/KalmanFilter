#include "KalmanFilter.h"

// Constructor to initialize the Kalman filter
KalmanFilter::KalmanFilter(float initial_x, float initial_p, float q, float r) {
    x = initial_x;  // Initial estimate
    p = initial_p;  // Initial covariance
    this->q = q;    // Process noise covariance
    this->r = r;    // Measurement noise covariance
}

// Prediction step
void KalmanFilter::predict(float u) {
    x = x + u;  // State prediction
    p = p + q;  // Update estimation error covariance with process noise
}

// Update step (measurement update)
void KalmanFilter::update(float z) {
    k = p / (p + r);  // Calculate Kalman gain
    x = x + k * (z - x);  // Update state estimate with measurement
    p = (1 - k) * p;  // Update estimation error covariance
}

// Return the current state estimate (filtered value)
float KalmanFilter::getEstimate() {
    return x;
}
