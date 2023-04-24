#include "main.h"

void AutonomousRoutine(Status Components_Status) {
    //grabs the one in front
    /*TranslateInches({
        .componentsStatus = Components_Status,
        .PID = true,
        .distance = 24,//15.5
        .reverse = false,
        .angle = 0,
        .timeout = 15000,
        //.subsystem = "intaker",
        //.subsystemTimeout = 3000,
    });
    return;*/
    TranslateInches({
        .componentsStatus = Components_Status,
        .PID = true,
        .distance = 15,//15.5,18
        .reverse = false,
        .angle = 0,
        .timeout = 10000,
        .subsystem = "intaker",
        .subsystemTimeout = 8000,
    });

    Stop();
    pros::delay(10000);
    //charges flywheel??
    /*ActivateSystem({
        .system = "flywheel",
        .activate = true,
    });*/

    //goes to shooting position
    TranslateInches({
        .PID = true,
        .distance = 9,//full 18
        .reverse = false,
        .angle = 45,
        //.translatePower = 10, //change later
        .timeout = 3000,
        .subsystem = "",
        .subsystemTimeout = 3000,
    });

    //adjust the angle for shooting
    TranslateInches({
        .PID = false,
        .distance = 0,
        .reverse = false,
        .angle = -20,
        //.translatePower = 10, //change later
        .timeout = 5000,
    });
    pros::delay(10000);

    //shoots first 3
    /*ActivateSystem({
       .system = "flywheel",
       .flywheelRPMs = 3122,
       .discs = 3,
    });*/

    //grabs the one in the line
    TranslateInches({
        .PID = false,
        .distance = 4,//full 18
        .reverse = false,
        .angle = 20,
       // .translatePower = 10, //change later
        .timeout = 5000,
        .subsystem = "intaker",
        .subsystemTimeout = 7000,
    });

    //goes back
    TranslateInches({
        .PID = false,
        .distance = 18,//full 18
        .reverse = true,
        .angle = 45,
        //.translatePower = 10, //change later
        .timeout = 5000,
    });

    //grabs the two remaining in the center
    TranslateInches({
        .PID = true,
        .distance = 37,
        .reverse = false,
        .angle = -45,
        //.translatePower = 10, //change later
        .timeout = 5000,
        .subsystem = "intaker",
        .subsystemTimeout = 7000,
    });

    //adjsuts angle for shooting, maybe get closer to the line
    TranslateInches({
        .PID = false,
        .distance = 0,
        .reverse = false,
        .angle = 90,
        //.translatePower = 10, //change later
        .timeout = 5000,
    });
    
    //shoots second batch of 3
    /*ActivateSystem({
       .system = "flywheel",
       .flywheelRPMs = 3122,
       .discs = 3,
    });*/

    TranslateInches({
        .PID = true,
        .distance = 18,//full 18
        .reverse = false,
        .angle = -180,
        //.translatePower = 10, //change later
        .timeout = 5000,
        .subsystem = "intaker",
        .subsystemTimeout = 7000,
    });

}
