#include "main.h"

void RestartComponents() {
    std::cout << "Inertial Sensor: " << Inertial_Sensor.get_rotation() << std::endl;
    std::cout << "Y Axis Encoder: " << Y_Axis_Encoder.get_value() << std::endl;

    Inertial_Sensor.reset();
    Y_Axis_Encoder.reset();

    std::cout << "Inertial Sensor: " << Inertial_Sensor.get_rotation() << std::endl;
    std::cout << "Y Axis Encoder: " << Y_Axis_Encoder.get_value() << std::endl;

    pros::delay(2000);
};
