#include "main.h"

void AutonomousRoutine() {
    // Move Roller
    TranslateInches(3, true, 0, 1, 50, "roller-backwards", 114);
    TranslateInches(3, false, 0, 1, 100, "", 0);

    // Pick first disc
    TranslateInches(8, false, -40.2, 1, 3000, "intaker", 1500);

    // Move backwards to turn
    TranslateInches(3, true, -40, 1, 1000, "intaker", 1000);

    // Charge Flywheel
    ActivateSystem("flywheel", 12000, true);

    // Move to first shooting position
    TranslateInches(30, false, 35, 1, 7000, "intaker", 2000);
    TranslateInches(0, false, -47, 1, 2000, "", 0);

    // Launch 3 discs without charging the flywheel
    ActivateSystem("flywheel 3", 11500, false);

    // T
    ActivateSystem("flywheel", 11500, false);
}
