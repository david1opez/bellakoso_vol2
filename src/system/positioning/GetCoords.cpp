#include "main.h"

double previousX = 0.0;
double previousY = 0.0;

double currentX = 0.0;
double currentY = 0.0;

double angle = 0.0;

void updateCoords(void* param) {
    while(true) {
        // Get values from the inertial sensor
        angle = Inertial_Sensor.get_rotation();
        double distance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0;

        // Calculate the change in position
        double deltaX = distance * cos(angle * M_PI / 180.0);
        double deltaY = distance * sin(angle * M_PI / 180.0);

        // Update the current position
        currentY = previousX + deltaX;
        currentX = previousY + deltaY;
    }
};

double GetX() {
    return currentX;
};

double GetY() {
    return currentY;
};

double GetAngle() {
    return angle;
};
