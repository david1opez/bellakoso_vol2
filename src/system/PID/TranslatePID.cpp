#include "main.h"

double startingDistance = 0.0;
double integralRaw = 0.0;
double lastError = 0.0;

double TranslatePID(double targetDistance, double currentDistance, double power) {
    double powerConstant = 8000;

    startingDistance = currentDistance;    

    double activeIntegralZone = startingDistance*0.45;
    double integralPowerLimit = 50 / TRANSLATE_KI;

    double error = targetDistance - currentDistance;
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
