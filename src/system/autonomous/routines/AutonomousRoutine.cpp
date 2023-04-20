#include "main.h"

void AutonomousRoutine(Status Components_Status) {
    // Move Roller
    TranslateInches({
        .componentsStatus = Components_Status,
        .PID = true,
        .distance = 14.75,
        .reverse = false,
        .angle = 0,
        .translatePower = 15, //change later
        .timeout = 5000,
        .subsystem = "intaker",
        .subsystemTimeout = 7000,
    });

    TranslateInches({
        
        .PID = false,
        .distance = 18,
        .reverse = false,
        .angle = -45,
        .translatePower = 10, //change later
        .timeout = 5000,
        .subsystem = "intaker",
        .subsystemTimeout = 7000,
    });


    
}
