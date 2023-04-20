#include "main.h"

bool IMU_Works = false;
bool Encoder_Works = false;

int timeout = 0;
int subsystemTimeout = 0;

void CheckComponents() {
    if(!Encoder_Works) {
        auto [x, IMU_Works] = CheckSensors();
    }

    if(!IMU_Works) {
        auto [Encoder_Works, x] = CheckSensors();
    }
};

double updateDistance (double previousDistance) {
    double currentDistance = 0.0;

    if(Encoder_Works) {
        currentDistance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0 - previousDistance;
    } else {
        currentDistance = GetBackupDistance() - previousDistance;
    }

    return currentDistance;
};

double updateAngle() {
    double currentAngle;

    if(IMU_Works) {
        currentAngle = Inertial_Sensor.get_rotation();
    } else {
        currentAngle = GetBackupAngle();
    }

    return currentAngle;
};

void TranslateInches(const TranslateParams& params) {
    // Setup
    auto [Encoder_Works, IMU_Works] = params.componentsStatus;

    if(!Encoder_Works) {
        auto [x, IMU_Works] = CheckSensors();
    }

    if(!IMU_Works) {
        auto [Encoder_Works, x] = CheckSensors();
    }
    
    timeout = params.timeout;
    subsystemTimeout = params.subsystemTimeout;

    double currentDistance = 0.0;
    double currentAngle = updateAngle();

    double angleMarginError = 3.5;
    double distanceMarginError = 0.5;

    double previousDistance = updateDistance(currentDistance);
    long previousAngle = updateAngle();

    double angleDiference = params.angle - currentAngle;
    double realDistance = params.distance / 2;
    double distanceDiference = params.distance;

    bool arrived = false;

    if(params.subsystem != "") {
        ActivateSystem({.system=params.subsystem,  .simultaneous = true, .activate=true});
    }

    while(!arrived && params.timeout > 0) {
        if((params.timeout - timeout) % 500 == 0) {
            if(!Encoder_Works) {
                auto [x, IMU_Works] = CheckSensors(true, previousDistance, previousAngle);
            }

            if(!IMU_Works) {
                auto [Encoder_Works, x] = CheckSensors(true, previousDistance, previousAngle);
            }
        }

        currentAngle = updateAngle();
        angleDiference = params.angle - currentAngle;

        if(params.subsystemTimeout <= 0) {
            ActivateSystem({.system=params.subsystem, .activate=false});
        }

        if(abs(angleDiference) >= angleMarginError) {
            if(angleDiference > angleMarginError) {
                Turn(1);
            }
            else if(angleDiference < -angleMarginError) {
                Turn(-1);
            }
        } else {
            int power = params.reverse ? -params.translatePower : params.translatePower;

            currentDistance = params.reverse ? -updateDistance(previousDistance) : updateDistance(previousDistance);
            
            if(abs(distanceDiference) > distanceMarginError) {
                distanceDiference = realDistance - currentDistance;

                if(distanceDiference > distanceMarginError) {
                    Move(realDistance, currentDistance, power);
                }
                else if(distanceDiference < -distanceMarginError) {
                    Move(realDistance, currentDistance, -power);
                }
            }
            else {
                arrived = true;
                Stop();
                ActivateSystem({
                    .system = params.subsystem,
                    .activate = false,
                });
            }
        }

        timeout-=5;
        subsystemTimeout-=5;
        pros::delay(5);
    }

    Stop();
    ActivateSystem({
        .system = params.subsystem,
        .activate = false,
    });
}