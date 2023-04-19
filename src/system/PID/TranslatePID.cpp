#include "main.h"

double startingDistance = 0.0;
double integralRaw = 0.0;
double lastError = 0.0;

double KP = 1000.0;
double KI = 500;
double KD = 0.000001;

double TranslatePID(double targetDistance, double currentDistance, double power) {
    std::cout << "Target distance: " << targetDistance << std::endl;
    std::cout << "Current distance: " << currentDistance << std::endl;
    targetDistance /= 2;
    double powerConstant = 8000;

    if(startingDistance == 0) {
        startingDistance = currentDistance;
    }

    double activeIntegralZone = startingDistance*0.45;
    double integralPowerLimit = 50 / KI;

    double error = targetDistance - currentDistance;
    double proportion = KP * error;

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
    
    double integral = KI * integralRaw;

    double derivative = KD * (error - lastError);

    lastError = error;

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

    std::cout << finalPower << std::endl;

    return finalPower;
}
