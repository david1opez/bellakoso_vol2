#include "main.h"

void RestartComponents() {    
    Inertial_Sensor.reset();
    Y_Axis_Encoder.reset();

    pros::delay(2000);
};
