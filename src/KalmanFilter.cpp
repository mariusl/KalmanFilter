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
