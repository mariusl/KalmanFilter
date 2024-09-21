#ifndef KalmanFilter_h
#define KalmanFilter_h

#include "Arduino.h"

class KalmanFilter {
    public:
        // Constructor
        KalmanFilter(float initial_x, float initial_p, float q, float r);
        
        // Public methods
        void predict(float u);
        void update(float z);
        float getEstimate();  // Returns the current estimate
        
    private:
        // Private variables
        float x;  // State estimate
        float p;  // Estimation error covariance
        float q;  // Process noise covariance
        float r;  // Measurement noise covariance
        float k;  // Kalman gain
};

#endif
