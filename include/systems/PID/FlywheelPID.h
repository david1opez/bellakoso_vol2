/**
 * @file systems/PID/RotatePID.h
 * 
 * This file contains the function for calculating the return value of the Rotation PID controller
*/

#include "main.h"

#ifndef __FLYWHEEL_PID_H__
#define __FLYWHEEL_PID_H__

/**
 * @brief Function for calculating the return value of the Rotation PID controller
 * 
 * @param tragetAngle The target Angle where to face the robot to
 * @param power
 * 
 * @return The power to which move the chassis motors
*/

double FlywheelPID(double targetRPMs);

#endif /* __FLYWHEEL_PID_H__ */
