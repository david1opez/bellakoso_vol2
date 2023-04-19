#include "main.h"

#ifndef __TRANSLATE_INCHES_H__
#define __TRANSLATE_INCHES_H__

struct TranslateParams {
    // Initialize parameter
    Status componentsStatus;
    // Translate parameters
    double distance = 0;
    bool reverse = false;
    double angle = 0;
    double rotatePower = 1;
    double translatePower = 1;
    int timeout = 5000;
    // Subsystem parameters
    std::string subsystem = "";
    int subsystemTimeout = 0;
    bool simultaneous = false;
    bool activate = false;
    bool backwards = false;
    // Flywheel parameters
    int flywheelRPMs = 191;
    bool chargeFlywheel = false;
    int discs = 0;
};

double updateDistance (double previousDistance);

double updateAngle();

void TranslateInches(const TranslateParams& params);

#endif // __TRANSLATE_INCHES_H__
