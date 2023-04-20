#include "main.h"

void Drive() {
    int power = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

    Right_Front_Wheel.move(power - turn);
    Right_Back_Top_Wheel.move(power - turn);
    Right_Back_Bottom_Wheel.move(power - turn);

    Left_Front_Wheel.move(power + turn);
    Left_Back_Top_Wheel.move(power + turn);
    Left_Back_Bottom_Wheel.move(power + turn);
};

void Turn(double targetAngle, double currentAngle, int power) {
    int voltage = power < 0 ? RotatePID(targetAngle, currentAngle, power) : -RotatePID(targetAngle, currentAngle, power);
    
    voltage = power < 0 ? 3000 : -3000;

    Right_Front_Wheel.move_voltage(voltage);
    Right_Back_Top_Wheel.move_voltage(voltage);
    Right_Back_Bottom_Wheel.move_voltage(voltage);

    Left_Front_Wheel.move_voltage(-voltage);
    Left_Back_Top_Wheel.move_voltage(-voltage);
    Left_Back_Bottom_Wheel.move_voltage(-voltage);
}

void Move(double targetDistance, std::optional<double> currentDistance, std::optional<int> power) {
    int voltage;

    if(power.has_value() && currentDistance.has_value()) {
        voltage = power < 0 ? -TranslatePID(targetDistance, currentDistance.value(), abs(power.value())) : TranslatePID(targetDistance, currentDistance.value(), power.value());
    } else {
        voltage = targetDistance < 0 ? -7000 : 7000;
    }

    Right_Front_Wheel.move_voltage(voltage);
    Right_Back_Top_Wheel.move_voltage(voltage);
    Right_Back_Bottom_Wheel.move_voltage(voltage);

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
