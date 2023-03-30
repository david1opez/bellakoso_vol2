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
