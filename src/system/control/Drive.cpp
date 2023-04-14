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

void TurnLeft(int voltage) {
    Right_Front_Wheel.move_voltage(voltage);
    Right_Back_Top_Wheel.move_voltage(voltage);
    Right_Back_Bottom_Wheel.move_voltage(voltage);

    Left_Front_Wheel.move_voltage(-voltage);
    Left_Back_Top_Wheel.move_voltage(-voltage);
    Left_Back_Bottom_Wheel.move_voltage(-voltage);
}

void TurnRight(int voltage) {
    Right_Front_Wheel.move_voltage(-voltage);
    Right_Back_Top_Wheel.move_voltage(-voltage);
    Right_Back_Bottom_Wheel.move_voltage(-voltage);

    Left_Front_Wheel.move_voltage(voltage);
    Left_Back_Top_Wheel.move_voltage(voltage);
    Left_Back_Bottom_Wheel.move_voltage(voltage);
}

void MoveForwards(int voltage) {
    Right_Front_Wheel.move_voltage(voltage);
    Right_Back_Top_Wheel.move_voltage(voltage);
    Right_Back_Bottom_Wheel.move_voltage(voltage);

    Left_Front_Wheel.move_voltage(voltage);
    Left_Back_Top_Wheel.move_voltage(voltage);
    Left_Back_Bottom_Wheel.move_voltage(voltage);
}

void MoveBackwards(int voltage) {
    Right_Front_Wheel.move_voltage(-voltage);
    Right_Back_Top_Wheel.move_voltage(-voltage);
    Right_Back_Bottom_Wheel.move_voltage(-voltage);

    Left_Front_Wheel.move_voltage(-voltage);
    Left_Back_Top_Wheel.move_voltage(-voltage);
    Left_Back_Bottom_Wheel.move_voltage(-voltage);
}

void Stop() {
    Right_Front_Wheel.move(0);
    Right_Back_Top_Wheel.move(0);
    Right_Back_Bottom_Wheel.move(0);

    Left_Front_Wheel.move(0);
    Left_Back_Top_Wheel.move(0);
    Left_Back_Bottom_Wheel.move(0);
}
