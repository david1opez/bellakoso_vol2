/*
==================================================
    MOTOR PORTS
==================================================
*/

// Chassis
#define RFWM_PORT 18 // Right Front Wheel Motor Port
#define RBTWM_PORT 9 // Right Back Top Wheel Motor Port
#define RBBWM_PORT 14 // Right Back Bottom Wheel Motor Port

#define LFWM_PORT 19 // Left Front Wheel Motor Port
#define LBTWM_PORT 7 // Left Back Top Wheel Motor Port
#define LBBWM_PORT 8 // Left Back Bottom Wheel Motor Port

// Intaker
#define INTAKER_PORT 5 // Intaker Motor Port

// Shooter
#define SHOOTER_PORT 15 // Intaker Motor Port

// Flywheel
#define FLYWHEEL_PORT 10 // Flywheel Motor Port

// Roller
#define ROLLER_PORT 3 // Roller Motor Port

/*
==================================================
    SENSOR PORTS
==================================================
*/

#define INERTIAL_SENSOR_PORT 16 // Inertial Sensor Port

#define Y_AXIS_ENCODER_TOP_PORT 1 // Y Axis Encoder Top Port
#define Y_AXIS_ENCODER_BOTTOM_PORT 2 // Y Axis Encoder Bottom Port

#define ROTATION_SENSOR_PORT 1 // Rotation Sensor Port

/*
==================================================
    OTHER PORTS
==================================================
*/

/*
==================================================
    CONSTANTS
==================================================
*/

#define M_PI 3.14159265358979323846
#define WHEEL_DIAMETER 2.75 // Wheel Diameter (in inches)

#define TRANSLATE_KP 1450
#define TRANSLATE_KI 620
#define TRANSLATE_KD 0.000001

#define ROTATE_KP 200
#define ROTATE_KI 0.8
#define ROTATE_KD 0.0001

#define FLYWHEEL_KP 175
#define FLYWHEEL_KI 0.00000001
#define FLYWHEEL_KD 0.00000001
