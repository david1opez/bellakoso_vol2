#include "main.h"

void Translate(float x, float y, float angle=0, int speed=100, int timeout=5000, std::string subsystem="", int subsystemTimeout=0) {
    // Get the current position of the robot
    float currentX = GetX();
    float currentY = GetY();
    float currentAngle = GetAngle();

    // Calculate the angle between the current position and the target position
    float targetAngle = atan2(y - currentY, x - currentX) * 180 / M_PI;

    // Calculate the distance between the current position and the target position
    float distance = sqrt(pow(x - currentX, 2) + pow(y - currentY, 2));

    auto updatePosition = [&]() {
        // Update the current position of the robot
        currentX = GetX();
        currentY = GetY();
        currentAngle = GetAngle();

        // Update the angle between the current position and the target position
        targetAngle = atan2(y - currentY, x - currentX) * 180 / M_PI;

        // Update the distance between the current position and the target position
        distance = sqrt(pow(x - currentX, 2) + pow(y - currentY, 2));
    };

    if(subsystem != "") {
        for(int i = 0; i < subsystemTimeout; i += 20) {
            ActivateSystem(subsystem);

            updatePosition();

            if(currentAngle > targetAngle + 1) {
                // Turn left
            } else if(currentAngle < targetAngle - 1) {
                // Turn right
            } else {
                if(distance > 0.5) {
                    // Move forward
                } else {
                    if(currentAngle > angle + 1) {
                        // Turn left
                    } else if(currentAngle < angle - 1) {
                        // Turn right
                    } else {
                        // Stop
                    }
                }
            }

            pros::delay(1);
        };

        ActivateSystem(subsystem, 0);

        updatePosition();

        bool arrived = false;

        while (!arrived && timeout > 0) { 
            if(currentAngle > targetAngle + 1) {
                // Turn left
            } else if(currentAngle < targetAngle - 1) {
                // Turn right
            } else {
                if(distance > 0.5) {
                    // Move forward
                } else {
                    if(currentAngle > angle + 1) {
                        // Turn left
                    } else if(currentAngle < angle - 1) {
                        // Turn right
                    } else {
                        // Stop
                    }
                }
            }

            timeout--;
            pros::delay(1);
        }

    }
};
