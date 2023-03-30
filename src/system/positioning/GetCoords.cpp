#include "main.h"

float previousX = 0.0;
float previousY = 0.0;

float currentX = 0.0;
float currentY = 0.0;

float angle = 0.0;

void updateCoords() {
    const float WHEEL_DIAMETER = 4.0;
    // Get values from the inertial sensor
    angle = inertialSensor.get_rotation();
    float distance = encoderX.getValue() * WHEEL_DIAMETER * M_PI / 360.0;

    // Calculate the change in x and y
    float deltaX = distance * cos(angle * M_PI / 180.0);
    float deltaY = distance * sin(angle * M_PI / 180.0);

    // Update the current x and y
    currentX = previousX + deltaX;
    currentY = previousY + deltaY;

    // Update the previous x and y
    previousX = currentX;
    previousY = currentY;
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
