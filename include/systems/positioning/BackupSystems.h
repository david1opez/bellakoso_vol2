#include "main.h"

#ifndef __BACKUP_SYSTEMS_H__
#define __BACKUP_SYSTEMS_H__

/**
 * @brief Get the distance the robot has travaled in case the encoders fail
 * 
*/

double GetBackupDistance();

/**
 * @brief Get the angle the robot has turned in case the inertial sensor fails
 * 
*/

double GetBackupAngle();

#endif // __BACKUP_SYSTEMS_H__
