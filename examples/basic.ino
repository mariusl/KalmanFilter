#include <KalmanFilter.h>

// Create a Kalman filter object
KalmanFilter kf(0.0, 1.0, 0.01, 1.0);  // Initial x, p, q, r

float sensorReading = 0.0;  // Level sensor reading
float control_input = 0.0;  // No control input since changes are slow

void setup() {
    // Initialize Serial communication for debugging
    Serial.begin(9600);
}

void loop() {
    // Read from the sensor (e.g., analogRead or digital sensor)
    sensorReading = analogRead(A0);  // Replace A0 with your sensor pin

    // Convert sensor reading to the appropriate range
    float level = map(sensorReading, 0, 1023, 0, 100);  // Assuming level is in 0-100 range

    // Prediction step (assuming slow change, so control input is 0)
    kf.predict(control_input);
    Serial.print("Predicted level: ");
    Serial.println(kf.getEstimate());

    // Update step with the new sensor measurement
    kf.update(level);
    Serial.print("Measured level: ");
    Serial.println(level);
    Serial.print("Filtered level: ");
    Serial.println(kf.getEstimate());
    Serial.println();

    // Wait a bit before reading the next value
    delay(1000);
}
