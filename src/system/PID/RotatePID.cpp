#include "main.h"

double startingAngleDiference = 0.0;
double rotateIntegralRaw = 0.0;
double lastRotateError = 0.0;

double RotatePID(double targetAngle, double currentAngle, double power) {
    double powerConstant = 8000;

    double angleDiference = targetAngle - currentAngle;

    startingAngleDiference = angleDiference;

    double activeIntegralZone = startingAngleDiference*0.45;
    double integralPowerLimit = 50 / ROTATE_KI;

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

    derivative = error == 0 ? 0 : derivative;

    double finalPower = ceil(proportion + integral + derivative);

    int maxValue = power*powerConstant;

    if (maxValue > 12000)
        maxValue = 12000;
    if(finalPower > maxValue) {
        finalPower = maxValue;
    }
    else if(finalPower < -maxValue) {
        finalPower = -maxValue;
    }
    else {
        finalPower = finalPower;
    }

    return finalPower;
}
