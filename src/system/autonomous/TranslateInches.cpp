#include "main.h"

void TranslateInches(double inches, bool reverse, double angle, double speed, int timeout, std::string subsystem, int subsystemTimeout) {
    double currentDistance = 0.0;
    double currentAngle = 0.0;

    double angleMarginError = 3;
    double distanceMarginError = 1;

    double previousDistance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0;

    currentAngle = Inertial_Sensor.get_rotation();

    double angleDiference = angle - currentAngle;
    double distanceDiference = inches;

    bool arrived = false;

    if(subsystem != "") {
        ActivateSystem(subsystem, 0, true);
    }
    while(!arrived && timeout > 0) {
        currentAngle = Inertial_Sensor.get_rotation();
        angleDiference = angle - currentAngle;

        if(subsystemTimeout <= 0) {
            ActivateSystem(subsystem, 0, false);
        }

        if(abs(angleDiference) >= angleMarginError) {
            if(angleDiference > angleMarginError) {
                Turn(1);
            }
            else if(angleDiference < -angleMarginError) {
                Turn(-1);
            }
        } else {
            int power = reverse ? -speed : speed;

            currentDistance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0 - previousDistance;
            currentDistance = reverse ? -currentDistance : currentDistance;

            if(abs(distanceDiference) > distanceMarginError) {
                distanceDiference = inches - currentDistance;

                if(distanceDiference > distanceMarginError) {
                    Move(power);
                }
                else if(distanceDiference < -distanceMarginError) {                    
                    Move(-power);
                }
            }
            else {
                arrived = true;
                Stop();
                ActivateSystem(subsystem, 0, false);
            }
        }

        timeout--;
        subsystemTimeout--;
        pros::delay(1);
    }

    Stop();
    ActivateSystem(subsystem, 0, false);

    while(subsystemTimeout > 0) {
        ActivateSystem(subsystem, 0, true);
        subsystemTimeout--;
        pros::delay(1);
    }

    ActivateSystem(subsystem, 0, false);

}