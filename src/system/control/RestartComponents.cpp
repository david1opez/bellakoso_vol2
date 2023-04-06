#include "main.h"

void RestartComponents() {
    pros::delay(1500);
    
    Inertial_Sensor.reset();
    Y_Axis_Encoder.reset();
};
