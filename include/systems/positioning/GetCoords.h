/**
 * @file GetCoords.h
 * 
 * @brief Contains the definition of the GetX, GetY and GetAngle functions
 * 
*/

#ifndef __GET_COORDS_H__
#define __GET_COORDS_H__

#include "main.h"

/**
 * @brief Updates the robot's position
 * 
*/

void updateCoords(void* param);

/**
 * @brief Gets the robot's x coordinate
 * 
 * @return The robot's x coordinate
 * 
*/

double GetX();

/**
 * @brief Gets the robot's y coordinate
 * 
 * @return The robot's y coordinate
 * 
*/

double GetY();

/**
 * @brief Gets the robot's angle
 * 
 * @return The robot's angle
 * 
*/

double GetAngle();

#endif // __GET_COORDS_H__
