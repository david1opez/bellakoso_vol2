#include "main.h"

void Drive() {
    int power = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

    int rightPower = -1.5*(power - turn);
    int leftPower = power + turn;
    if (rightPower > 127)
    {
        rightPower = 127;
    }
    else if (rightPower < -127)
    {
        rightPower = -127;
    }
    Right_Front_Wheel.move(rightPower);//change back for driver
    Right_Back_Top_Wheel.move(rightPower);
    Right_Back_Bottom_Wheel.move(rightPower);

    Left_Front_Wheel.move(leftPower);
    Left_Back_Top_Wheel.move(leftPower);
    Left_Back_Bottom_Wheel.move(leftPower);
};

void Turn(double targetAngle, double currentAngle, int power) {
    int voltage = power < 0 ? RotatePID(targetAngle, currentAngle, power) : -RotatePID(targetAngle, currentAngle, power);
    
    voltage = power < 0 ? 5000 : -5000;
    int rightPower = 1.5*(voltage);
    Right_Front_Wheel.move_voltage(voltage);
    Right_Back_Top_Wheel.move_voltage(voltage);
    Right_Back_Bottom_Wheel.move_voltage(voltage);

    voltage *= -1;
    Left_Front_Wheel.move_voltage(-voltage);
    Left_Back_Top_Wheel.move_voltage(-voltage);
    Left_Back_Bottom_Wheel.move_voltage(-voltage);
}

void Move(double targetDistance, std::optional<double> currentDistance, std::optional<int> power) {
    int voltage;

    if(power.has_value() && currentDistance.has_value()) {
        voltage = power < 0 ? -TranslatePID(targetDistance, currentDistance.value(), abs(power.value())) : TranslatePID(targetDistance, currentDistance.value(), power.value());
    } else {
        voltage = targetDistance < 0 ? -2500 : 2500;
    }
    int rightPower = 1.5*(voltage);
    Right_Front_Wheel.move_voltage(rightPower);
    Right_Back_Top_Wheel.move_voltage(rightPower);
    Right_Back_Bottom_Wheel.move_voltage(rightPower);

    voltage *= -1;
    Left_Front_Wheel.move_voltage(voltage);
    Left_Back_Top_Wheel.move_voltage(voltage);
    Left_Back_Bottom_Wheel.move_voltage(voltage);
}

void Stop() {
    Right_Front_Wheel.move(0);
    Right_Back_Top_Wheel.move(0);
    Right_Back_Bottom_Wheel.move(0);

    Left_Front_Wheel.move(0);
    Left_Back_Top_Wheel.move(0);
    Left_Back_Bottom_Wheel.move(0);
}
