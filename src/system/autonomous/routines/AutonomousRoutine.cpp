#include "main.h"

void AutonomousRoutine() {
    // Move Roller
    TranslateInches(3, true, 0, 1, 50, "roller-backwards", 114);
    TranslateInches(3, false, 0, 1, 100, "", 0);

    // Pick first disc
    TranslateInches(11, false, -40, 1, 3000, "intaker", 1500);

    // Move to first shooting position
    TranslateInches(1, true, -40, 1, 1000, "intaker", 1000);
    TranslateInches(1, false, 45, 1, 2000, "intaker", 0);
}
