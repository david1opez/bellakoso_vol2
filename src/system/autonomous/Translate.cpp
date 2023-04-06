#include "main.h"

void TurnLeft(int speed) {
    Right_Front_Wheel.move(speed);
    Right_Back_Top_Wheel.move(speed);
    Right_Back_Bottom_Wheel.move(speed);

    Left_Front_Wheel.move(-speed);
    Left_Back_Top_Wheel.move(-speed);
    Left_Back_Bottom_Wheel.move(-speed);
}

void TurnRight(int speed) {
    Right_Front_Wheel.move(-speed);
    Right_Back_Top_Wheel.move(-speed);
    Right_Back_Bottom_Wheel.move(-speed);

    Left_Front_Wheel.move(speed);
    Left_Back_Top_Wheel.move(speed);
    Left_Back_Bottom_Wheel.move(speed);
}

void MoveForwards(int speed) {
    Right_Front_Wheel.move(speed);
    Right_Back_Top_Wheel.move(speed);
    Right_Back_Bottom_Wheel.move(speed);

    Left_Front_Wheel.move(speed);
    Left_Back_Top_Wheel.move(speed);
    Left_Back_Bottom_Wheel.move(speed);
}

void MoveBackwards(int speed) {
    Right_Front_Wheel.move(-speed);
    Right_Back_Top_Wheel.move(-speed);
    Right_Back_Bottom_Wheel.move(-speed);

    Left_Front_Wheel.move(-speed);
    Left_Back_Top_Wheel.move(-speed);
    Left_Back_Bottom_Wheel.move(-speed);
}

void Stop(int speed) {
    Right_Front_Wheel.move(0);
    Right_Back_Top_Wheel.move(0);
    Right_Back_Bottom_Wheel.move(0);

    Left_Front_Wheel.move(0);
    Left_Back_Top_Wheel.move(0);
    Left_Back_Bottom_Wheel.move(0);
}

void Translate(double x, double y, std::optional<double> angle=std::nullopt, std::optional<int> speed=std::nullopt, std::optional<int> timeout=std::nullopt, std::optional<std::string> subsystem=std::nullopt, std::optional<int> subsystemTimeout=std::nullopt) {
    // Get the current position of the robot
    float currentTranslateX = GetX();
    float currentTranslateY = GetY();
    float currentTranslateAngle = GetAngle();

    // Calculate the angle between the current position and the target position
    float targetAngle = atan2(y - currentTranslateY, x - currentTranslateX) * 180 / M_PI;

    // Calculate the distance between the current position and the target position
    float distance = sqrt(pow(x - currentTranslateY, 2) + pow(y - currentTranslateY, 2));

    auto updatePosition = [&]() {
        // Update the current position of the robot
        currentTranslateX = GetX();
        currentTranslateY = GetY();
        currentTranslateAngle = GetAngle();

        // Update the angle between the current position and the target position
        targetAngle = atan2(y - currentTranslateY, x - currentTranslateX) * 180 / M_PI;

        // Update the distance between the current position and the target position
        distance = sqrt(pow(x - currentTranslateX, 2) + pow(y - currentTranslateY, 2));
        
        std::cout << "X: " << currentTranslateX << " Y: " << currentTranslateY << " Angle: " << currentTranslateAngle << std::endl;
    };

    if(subsystem != "") {
        for(int i = 0; i < subsystemTimeout; i += 20) {
            // ActivateSystem(subsystem);

            updatePosition();

            if(currentTranslateAngle > targetAngle + 1) {
                // Turn left
            } else if(currentTranslateAngle < targetAngle - 1) {
                // Turn right
            } else {
                if(distance > 0.5) {
                    // Move forward
                    MoveForwards(TranslatePID(x,y,1));
                } else {
                    if(currentTranslateAngle > angle.value_or(0) + 1) {
                        // Turn left
                    } else if(currentTranslateAngle < angle.value_or(0) - 1) {
                        // Turn right
                    } else {
                        // Stop
                    }
                }
            }

            pros::delay(1);
        };

        ActivateSystem(subsystem.value_or(""), 0);

        updatePosition();

        bool arrived = false;

        while (!arrived && timeout > 0) { 
            if(currentTranslateAngle > targetAngle + 1) {
                // Turn left
            } else if(currentTranslateAngle < targetAngle - 1) {
                // Turn right
            } else {
                if(distance > 0.5) {
                    // Move forward
                } else {
                    if(currentTranslateAngle > angle.value_or(0) + 1) {
                        // Turn left
                    } else if(currentTranslateAngle < angle.value_or(0) - 1) {
                        // Turn right
                    } else {
                        // Stop
                    }
                }
            }

            timeout.has_value() ? timeout.value() -= 1 : timeout = 4999;

            pros::delay(1);
        }

    }
};
