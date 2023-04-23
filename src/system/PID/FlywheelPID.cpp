#include "main.h"

double startingrRPMs = 0.0;
double flywheelIntegralRaw = 0.0;
double flywheelLastError = 0.0;

double FlywheelPID(double targetRPMs) {
    targetRPMs += 65;
    double powerConstant = 8000;

    double currentRPMs = (Rotation_Sensor.get_velocity() / 100) * 16.66666;

    startingrRPMs = currentRPMs;

    double activeIntegralZone = startingrRPMs*0.45;
    double integralPowerLimit = 50 / FLYWHEEL_KI;

    double error = targetRPMs - currentRPMs;
    double proportion = FLYWHEEL_KP * error;

    if (fabs(error) > activeIntegralZone && error != 0) {
        flywheelIntegralRaw = 0;
    }
    else {
        flywheelIntegralRaw += error;
    }

    if(flywheelIntegralRaw > integralPowerLimit) {
        flywheelIntegralRaw = integralPowerLimit;
    }
    else if (flywheelIntegralRaw < -integralPowerLimit) {
        flywheelIntegralRaw = -integralPowerLimit;
    }
    else {
        flywheelIntegralRaw = flywheelIntegralRaw;
    }
    
    double integral = FLYWHEEL_KI * flywheelIntegralRaw;

    double derivative = FLYWHEEL_KD * (error - flywheelLastError);

    flywheelLastError = error;

    derivative = error == 0 ? 0 : derivative;

    double finalPower = ceil(proportion + integral + derivative);
    
    int maxValue = 12000;

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
