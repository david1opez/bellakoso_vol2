#include "main.h"

double startingDistance = 0.0;
double integralRaw = 0.0;
double lastError = 0.0;

double TranslatePID(double targetX, double targetY, double power) {
    double powerConstant = 8000;

    double currentX = GetX();
    double currentY = GetY();

    double currentDistance = sqrt(pow((targetX - currentX), 2)+(pow((targetY - currentY), 2)));

    if(startingDistance == 0) {
        startingDistance = currentDistance;
    }

    double activeIntegralZone = startingDistance*0.45;
    double integralPowerLimit = 50 / TRANSLATE_KI;

    double error = currentDistance;
    double proportion = TRANSLATE_KP * error;

    if (fabs(error) > activeIntegralZone && error != 0) {
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
    
    double integral = TRANSLATE_KI * integralRaw;

    double derivative = TRANSLATE_KD * (error - lastError);

    lastError = error;

    derivative = error == 0 ? 0 : derivative;

    double finalPower = ceil(proportion + integral + derivative);

    if(finalPower > power*powerConstant) {
        finalPower = power*powerConstant;
    }
    else if(finalPower < -power*powerConstant) {
        finalPower = -power*powerConstant;
    }
    else {
        finalPower = finalPower;
    }

    return finalPower;
}
