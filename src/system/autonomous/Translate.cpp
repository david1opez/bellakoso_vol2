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

    float initialAngle = currentTranslateAngle;

    // Calculate the angle between the current position and the target position
    float targetAngle = (atan2(x - currentTranslateX, y - currentTranslateY) * 180 / M_PI) - initialAngle;

    // Calculate the distance between the current position and the target position
    float distance = sqrt(pow(x - currentTranslateX, 2) + pow(y - currentTranslateY, 2));

    auto updatePosition = [&]() {
        // Update the current position of the robot
        currentTranslateX = GetX();
        currentTranslateY = GetY();
        currentTranslateAngle = GetAngle();

        // Update the angle between the current position and the target position
        targetAngle = (atan2(x - currentTranslateX, y - currentTranslateY) * 180 / M_PI) - initialAngle;

        // Update the distance between the current position and the target position
        distance = sqrt(pow(y - currentTranslateY, 2) + pow(x - currentTranslateX, 2));

        while(std::isnan(currentTranslateX) || std::isnan(currentTranslateY)) {
            currentTranslateX = GetX();
            currentTranslateY = GetY();
            currentTranslateAngle = GetAngle();
            std::cout << "Waiting for sensors to initialize..." << std::endl;
        }
    };

    bool arrived = false;
    bool translateAngleArrived = false;

    double turnErrorMargin = 1;
    double moveErrorMargin = 8;

    timeout = timeout.value_or(6000);

    while (!arrived && timeout.value() > 0) {
        updatePosition();

        double translateAngleDifference = targetAngle - currentTranslateAngle;

        if(abs(translateAngleDifference) > turnErrorMargin) {
            if(translateAngleDifference > turnErrorMargin) {
                TurnRight(5000);
            }
            else if(translateAngleDifference < -turnErrorMargin) {
                TurnLeft(5000);
            }

            if(translateAngleArrived) {
                translateAngleArrived = false;
                turnErrorMargin -= 1;
            }
        }
        else {
            translateAngleArrived = true;

            if(turnErrorMargin < 10) {
                turnErrorMargin += 0.1;
            }

            if(distance <= moveErrorMargin) {

                if(angle.has_value()) {
                    double angleDifference = angle.value() - Inertial_Sensor.get_rotation();
                    bool angleArrived = false;

                    turnErrorMargin = 1;
                    
                    while(!angleArrived && timeout.value() > 0) {
                        angleDifference = angle.value() - Inertial_Sensor.get_rotation();

                        if(abs(angleDifference) > turnErrorMargin) {
                            if(angleDifference > turnErrorMargin) {
                                TurnRight(5000);
                            }
                            else if(angleDifference < -turnErrorMargin) {
                                TurnLeft(5000);
                            } else {
                                angleArrived = true;
                            }
                        }

                        timeout.value() -= 1;
                        pros::delay(1);
                    }
                }

                arrived = true;
                Stop();
            } 
            else {
                MoveForwards(5000);
            }
        }
        
        timeout.value() -= 1;
        pros::delay(1);
    }
};
