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

double GetBackupDistancee() {
    double Left_Side_Encoders_Value = (Left_Back_Bottom_Wheel.get_position() + Left_Back_Top_Wheel.get_position() + Left_Front_Wheel.get_position()) / 3;
    double Right_Side_Encoders_Value = (-Right_Back_Bottom_Wheel.get_position() - Right_Back_Top_Wheel.get_position()) / 2;

    double Left_Side_Distance = Left_Side_Encoders_Value * 3.125 * M_PI / 360.0;
    double Right_Side_Distance = Right_Side_Encoders_Value * 3.125 * M_PI / 360.0;

    double Average_Distance = (Left_Side_Distance + Right_Side_Distance) / 2;

    return Average_Distance;
}


double updateDistance (double previousDistance) {
    double currentDistance = 0.0; 
    currentDistance = GetBackupDistancee() - previousDistance;
    std::cout << currentDistance << std::endl;
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
        ActivateSystem({.system=params.subsystem,  .simultaneous = true, .activate=true, .backwards=params.backwards});
    }

    while(!arrived && timeout > 0) {
        
        std::cout << angleDiference << std::endl;
        currentAngle = updateAngle();
        angleDiference = params.angle - currentAngle;

        if(subsystemTimeout <= 0) {
            ActivateSystem({.system=params.subsystem, .activate=false});
        }

        if(abs(angleDiference) >= angleMarginError) {
            if(angleDiference > angleMarginError) {
                Turn(params.angle, currentAngle, 1);
            }
            else if(angleDiference < -angleMarginError) {
                Turn(params.angle, currentAngle, -1);
            }
        } else {
            int power = params.reverse ? -params.translatePower : params.translatePower;


            currentDistance = params.reverse ? -updateDistance(previousDistance) : updateDistance(previousDistance);
            
            if(abs(distanceDiference) > distanceMarginError) {
                distanceDiference = realDistance - currentDistance;

                if(distanceDiference > distanceMarginError) {
                    if(params.PID) {
                        Move(realDistance, currentDistance, power);
                    } else {
                        Move(power);
                    }
                }
                else if(distanceDiference < -distanceMarginError) {
                    if(params.PID) {
                        Move(realDistance, currentDistance, -power);
                    } else {
                        Move(-power);
                    }
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

    while(subsystemTimeout > 0) {
        ActivateSystem({.system=params.subsystem,  .simultaneous = true, .activate=true, .backwards=params.backwards});
        subsystemTimeout-=5;
        pros::delay(5);
    }

    Stop();
    ActivateSystem({
        .system = params.subsystem,
        .activate = false,
    });
}