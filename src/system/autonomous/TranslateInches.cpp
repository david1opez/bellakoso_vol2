#include "main.h"

double previousDistance = 0.0;

void TranslateInches(double inches, bool reverse, double angle, double speed) {
    double currentDistance = 0.0;
    double currentAngle = 0.0;

    double angleMarginError = 2.5;
    double distanceMarginError = 1;

    Inertial_Sensor.set_rotation(0);

    currentAngle = Inertial_Sensor.get_rotation();
    currentDistance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0;

    double angleDiference = angle - currentAngle;
    double distanceDiference = inches - currentDistance - previousDistance;

    bool arrived = false;

    while(!arrived) {
        currentAngle = Inertial_Sensor.get_rotation();
        angleDiference = angle - currentAngle;

        if(abs(angleDiference) >= angleMarginError) {
            int voltage = 3000;

            if(angleDiference > angleMarginError) {
                TurnRight(voltage);
            }
            else if(angleDiference < -angleMarginError) {
                TurnLeft(voltage);
            }
        } else {
            int voltage = 12000 * speed;

            double percentTravelled = currentDistance / inches;

            if(percentTravelled < 0.3) {
                voltage *= 0.50;
            }
            else if(percentTravelled < 0.6) {
                voltage *= 0.45;
            }
            else if(percentTravelled < 0.9) {
                voltage *= 0.35;
            }
            else {
                voltage *= 0.30;
            }

            currentDistance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0 - previousDistance;

            if(abs(distanceDiference) > distanceMarginError) {
                distanceDiference = inches - currentDistance;

                if(distanceDiference > distanceMarginError) {
                    MoveForwards(voltage);
                }
                else if(distanceDiference < -distanceMarginError) {                    
                    MoveBackwards(voltage);
                }
            }
            else {
                arrived = true;
                Stop();
            }
        }
    }

    previousDistance = currentDistance;
}