/**
 * @file systems/PID/TranslatePID.h
 * 
 * This file contains the function for calculating the return value of the translation PID controller
*/

#include "main.h"

#ifndef __TRANSLATE_PID_H__
#define __TRANSLATE_PID_H__

/**
 * @brief Function for calculating the return value of the translation PID controller
 * 
 * @param x The target X where to move the robot to
 * @param y The target Y where to move the robot to
 * @param power
 * 
 * @return The power to which move the chassis motors
*/

double TranslatePID(double x, double y, double power);

#endif /* __TRANSLATE_PID_H__ */
