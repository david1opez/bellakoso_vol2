#include "main.h"

double previousX = 0.0;
double previousY = 0.0;

double currentX = 0.0;
double currentY = 0.0;

double angle = 0.0;

bool useBackup = false;

void updateCoords(void* param) {
    while(true) {
        if(std::isinf(Inertial_Sensor.get_rotation()) || std::isnan(Inertial_Sensor.get_rotation())) {
            angle = GetBackupAngle();
            Inertial_Sensor.set_rotation(angle);
        } else {
            angle = Inertial_Sensor.get_rotation();
        }

        angle = Inertial_Sensor.get_rotation();

        double distance = Y_Axis_Encoder.get_value() * WHEEL_DIAMETER * M_PI / 360.0;

        if(std::isinf(distance) || std::isnan(distance)) {
            useBackup = true;
        }

        if(useBackup) {
            distance = GetBackupDistance();
        }

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
