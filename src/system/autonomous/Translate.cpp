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

void Stop() {
    Right_Front_Wheel.move(0);
    Right_Back_Top_Wheel.move(0);
    Right_Back_Bottom_Wheel.move(0);

    Left_Front_Wheel.move(0);
    Left_Back_Top_Wheel.move(0);
    Left_Back_Bottom_Wheel.move(0);
}

void Translate(double x, double y,std::optional<std::string> subsystem, std::optional<double> angle, std::optional<int> speed, std::optional<int> timeout, std::optional<int> subsystemTimeout) {
    // Get the current position of the robot
    float currentTranslateX = GetX();
    float currentTranslateY = GetY();
    float currentTranslateAngle = GetAngle();

    // Calculate the angle between the current position and the target position
    float targetAngle = atan2(x - currentTranslateX, y - currentTranslateY) * 180 / M_PI;

    // Calculate the distance between the current position and the target position
    float distance = sqrt(pow(x - currentTranslateX, 2) + pow(y - currentTranslateY, 2));

    auto updatePosition = [&]() {
        // Update the current position of the robot
        currentTranslateX = GetX();
        currentTranslateY = GetY();
        currentTranslateAngle = GetAngle();

        // Update the angle between the current position and the target position
        targetAngle = atan2(x - currentTranslateX, y - currentTranslateY) * 180 / M_PI;

        // Update the distance between the current position and the target position
        distance = sqrt(pow(x - currentTranslateX, 2) + pow(y - currentTranslateY, 2));

        while(std::isnan(currentTranslateX) || std::isnan(currentTranslateY)) {
            std::cout << "Waiting for sensors to initialize..." << std::endl;
            currentTranslateX = GetX();
            currentTranslateY = GetY();
            currentTranslateAngle = GetAngle();
        }

        std::cout << "Current X: " << currentTranslateX << std::endl;
        std::cout << "Current Y: " << currentTranslateY << std::endl;
        std::cout << "Distance: " << distance << std::endl;
    };
    
    subsystem = subsystem.value_or("");
    timeout = timeout.value_or(5000);

    if(subsystem != "") {
        for(int i = 0; i < subsystemTimeout; i += 20) {
            // ActivateSystem(subsystem);

            updatePosition();

            if(currentTranslateAngle > targetAngle + 1) {
                // Turn left
            } else if(currentTranslateAngle < targetAngle - 1) {
                // Turn right
                // TurnRight(RotatePID(targetAngle, 1));
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
    }
    else {
        bool arrived = false;

        while (!arrived && timeout > 0) {
            updatePosition();

            double errorMargin = 1;
            double angleDifference = targetAngle - currentTranslateAngle;

            std::cout << "Angle Difference: " << angleDifference << std::endl;

            if(abs(angleDifference) > errorMargin) {
                if(angleDifference > 0) {
                    while (angleDifference > 0 )
                    {
                        currentTranslateAngle = GetAngle();
                        angleDifference = targetAngle - currentTranslateAngle;
                        TurnRight(40);
                    }
                } else if (angleDifference < 0) {
                    while (angleDifference > 0)
                    {
                        currentTranslateAngle = GetAngle();
                        angleDifference = targetAngle - currentTranslateAngle;
                        TurnLeft(30);
                    }
                }
            }
            else {
                if(distance > 0.5) {
                    MoveForwards(30);
                } 
                else if (distance <= 0.5) {
                    arrived = true;

                    if(currentTranslateAngle > angle.value_or(0) + 1) {
                        // Turn left
                    } else if(currentTranslateAngle < angle.value_or(0) - 1) {
                        // Turn right
                    } else {
                        // Stop
                        Stop();
                        break;
                    }
                }
            }

            pros::delay(1);
        }
    }
};
