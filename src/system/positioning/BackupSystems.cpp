#include "main.h"

double GetBackupDistance() {
    double Left_Side_Encoders_Value = (Left_Back_Bottom_Wheel.get_position() + Left_Back_Top_Wheel.get_position() + Left_Front_Wheel.get_position()) / 3;
    double Right_Side_Encoders_Value = (Right_Back_Bottom_Wheel.get_position() + Right_Back_Top_Wheel.get_position() + Right_Front_Wheel.get_position()) / 3;

    std::cout << Left_Side_Encoders_Value << " " << Right_Side_Encoders_Value << std::endl;

    double Left_Side_Distance = Left_Side_Encoders_Value * 3.125 * M_PI / 360.0;
    double Right_Side_Distance = Right_Side_Encoders_Value * 3.125 * M_PI / 360.0;

    double Average_Distance = (Left_Side_Distance + Right_Side_Distance) / 2;

    return Average_Distance;
}

double GetBackupAngle() {
    double Left_Side_Encoders_Value = (Left_Back_Bottom_Wheel.get_position() + Left_Back_Top_Wheel.get_position() + Left_Front_Wheel.get_position()) / 3;
    double Right_Side_Encoders_Value = (Right_Back_Bottom_Wheel.get_position() + Right_Back_Top_Wheel.get_position() + Right_Front_Wheel.get_position()) / 3;

    double Left_Side_Distance = Left_Side_Encoders_Value * 3.125 * M_PI / 360.0;
    double Right_Side_Distance = Right_Side_Encoders_Value * 3.125 * M_PI / 360.0;

    double angle = (Left_Side_Distance - Right_Side_Distance) / 11;

    return angle*100;
};