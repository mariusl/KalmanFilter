# Kalman Filter

## How to Use:
In your Arduino sketch, include the library by adding #include <KalmanFilter.h>.
Use the KalmanFilter class as shown in the example sketch above.

## Explanation:
KalmanFilter constructor: Takes four parameters:

	initial_x: Initial state estimate.
	
	initial_p: Initial estimation error covariance.
	
	q: Process noise covariance (model noise).
	
	r: Measurement noise covariance (sensor noise).
	
	
predict(): This performs the prediction step based on the previous estimate.

update(): This takes a new sensor measurement and updates the state estimate.

getEstimate(): This method returns the current filtered estimate.

## Notes:
You can adjust the q and r values based on the characteristics of your system and sensor noise level.
