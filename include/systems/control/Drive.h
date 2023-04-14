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
 * @brief Turns the robot left at a given voltage
 * 
 * @param voltage The voltage to turn the robot at
 * 
*/

void TurnLeft(int voltage);

/**
 * @brief Turns the robot right at a given voltage
 * 
 * @param voltage The voltage to turn the robot at
 * 
*/

void TurnRight(int voltage);

/**
 * @brief Moves the robot forwards at a given voltage
 * 
 * @param voltage The voltage to move the robot at
 * 
*/

void MoveForwards(int voltage);

/**
 * @brief Moves the robot backwards at a given voltage
 * 
 * @param voltage The voltage to move the robot at
 * 
*/

void MoveBackwards(int voltage);

/**
 * @brief Stops the robot
 * 
*/
void Stop();

#endif // __DRIVE_H__
