#include "main.h"

double startingAngleDiference = 0.0;
double integralRaw = 0.0;
double lastError = 0.0;

double RotatePID(float targetAngle, float power=1) {
    double powerConstant = 5000;

    double angleDiference = targetAngle - Inertial_Sensor.get_rotation();

    if(startingAngleDiference == 0) {
        startingAngleDiference = angleDiference;
    }

    double activeIntegralZone = startingAngleDiference*0.45;
    double integralPowerLimit = 50 / ROTATE_KI;

    Inertial_Sensor.tare_rotation();

    double error = angleDiference;
    double proportion = ROTATE_KP * error;

    if (fabs(error) < activeIntegralZone && error != 0) {
        integralRaw = 0;
    }
    else {
        integralRaw += error;
    }

    if(integralRaw > integralPowerLimit) {
        integralRaw = integralPowerLimit;
    }
    else if (integralRaw < -integralPowerLimit) {
        integralRaw = -integralPowerLimit;
    }
    else {
        integralRaw = integralRaw;
    }

    double integral = ROTATE_KI * integralRaw;

    double derivative = ROTATE_KD * (error - lastError);
    lastError = error;

    derivative = error == 0 ? 0 : derivative ;

    double finalPower = ceil(proportion + integral + derivative);

    if(finalPower > power*powerConstant) {
        finalPower = power*powerConstant;
    }
    else if (finalPower < -power*powerConstant) {
        finalPower = -power*powerConstant;
    }
    else {
        finalPower = finalPower;
    }

    return finalPower;
}
