#include "main.h"

void RestartComponents() {
    pros::delay(1500);
    
    inertialSensor.reset();
    Y_Axis_Encoder.reset();
};
