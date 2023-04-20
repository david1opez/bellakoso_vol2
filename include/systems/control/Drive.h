/**
 * @file systems/control/Drive.h
 * 
 * @brief Contains the definition of the Drive function
 * 
*/

#ifndef __DRIVE_H__
#define __DRIVE_H__

#include "main.h"

/**
 * @brief Drives the robot using the controller's joysticks
 * 
*/

void Drive();

/**
 * @brief Turns the robot left or right
 * 
 * @param power The voltage percent to turn the robot at. If set to negative, the robot will turn left. If set to positive, the robot will turn right
 * 
*/

void Turn(double targetAngle, double currentAngle, int power);

/**
 * @brief Moves the robot forwards or backwards
 * 
 * @param power The voltage percent to move the robot at. If set to negative, the robot will move backwards. If set to positive, the robot will move forwards
 * 
*/

void Move(
    double targetDistance,
    std::optional<double> currentDistance = std::nullopt,
    std::optional<int> power = std::nullopt
);

/**
 * @brief Stops the robot
 * 
*/
void Stop();

#endif // __DRIVE_H__
