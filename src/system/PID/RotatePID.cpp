#include "main.h"

double startingAngleDiference = 0.0;
double rotateIntegralRaw = 0.0;
double lastRotateError = 0.0;

double RotatePID(double targetAngle, double power=1) {
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
        rotateIntegralRaw = 0;
    }
    else {
        rotateIntegralRaw += error;
    }

    if(rotateIntegralRaw > integralPowerLimit) {
        rotateIntegralRaw = integralPowerLimit;
    }
    else if (rotateIntegralRaw < -integralPowerLimit) {
        rotateIntegralRaw = -integralPowerLimit;
    }
    else {
        rotateIntegralRaw = rotateIntegralRaw;
    }

    double integral = ROTATE_KI * rotateIntegralRaw;

    double derivative = ROTATE_KD * (error - lastRotateError);
    lastRotateError = error;

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
