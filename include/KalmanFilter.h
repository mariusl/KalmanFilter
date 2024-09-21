/*
 * Kalman filter.
 *
 * Copyright (C) 2024  Marius Liebenberg <marius@protomac.co.za>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
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
