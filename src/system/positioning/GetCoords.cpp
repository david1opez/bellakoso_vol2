#include "main.h"

float previousX = 0.0;
float previousY = 0.0;

float currentX = 0.0;
float currentY = 0.0;

float angle = 0.0;

void updateCoords(void* param) {
    while(true) {
        // Get values from the inertial sensor
        angle = inertialSensor.get_rotation();
        float distance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0;

        // Calculate the change in position
        float deltaX = distance * cos(angle * M_PI / 180.0);
        float deltaY = distance * sin(angle * M_PI / 180.0);

        // Update the current position
        currentY = previousX + deltaX;
        currentX = previousY + deltaY;

        std::cout << "X: " << currentX << " Y: " << currentY << " Angle: " << angle << std::endl;
    }
};

float GetX() {
    return currentX;
};

float GetY() {
    return currentY;
};

float GetAngle() {
    return angle;
};
