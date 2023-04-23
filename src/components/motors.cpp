#include "main.h"

// Chassis Right Motors
pros::Motor Right_Front_Wheel(RFWM_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // Right Front Wheel Motor
pros::Motor Right_Back_Top_Wheel(RBTWM_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // Right Back Top Wheel Motor
pros::Motor Right_Back_Bottom_Wheel(RBBWM_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // Right Back Bottom Wheel Motor

// Chassis Left Motors
pros::Motor Left_Front_Wheel(LFWM_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // Left Front Wheel Motor
pros::Motor Left_Back_Top_Wheel(LBTWM_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // Left Back Top Wheel Motor
pros::Motor Left_Back_Bottom_Wheel(LBBWM_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // Left Back Bottom Wheel Motor

// Intaker Motor
pros::Motor Intaker(INTAKER_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // Intaker Motor

// Shooter Motor
pros::Motor Shooter(SHOOTER_PORT, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_DEGREES); // Shooter Motor

// Flywheel Motor
pros::Motor Flywheel(FLYWHEEL_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // Flywheel Motor

// Roller Motor
pros::Motor Roller(ROLLER_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // Roller Motors

// Expansion Motor
pros::Motor Expansion_Motor(EXPANSION_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // Expansion Motor
