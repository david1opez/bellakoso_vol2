#include "main.h"

pros::ADIEncoder Y_Axis_Encoder(Y_AXIS_ENCODER_TOP_PORT, Y_AXIS_ENCODER_BOTTOM_PORT, false);

pros::IMU Inertial_Sensor(INERTIAL_SENSOR_PORT);