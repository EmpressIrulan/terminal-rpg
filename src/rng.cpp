#include "rng.h"
#include <cstdlib>
#include <ctime>

namespace rng{

// Tracked so seed() can be called from anywhere without re-seeding: seeding
// twice in one run would replay the same sequence from a new start point.
static bool seeded = false;

void seed(){
    if(seeded){
        return;
    }

    srand(time(nullptr));
    seeded = true;
}

bool rollChance(int percent){
    if(percent <= 0){
        return false;
    }

    if(percent >= 100){
        return true;
    }

    return rollRange(0, 99) < percent;
}

int rollRange(int min, int max){
    if(max <= min){
        return min;
    }

    // rand() % n skews slightly toward low values when n doesn't divide the
    // generator's range evenly. Harmless for the small ranges used here, and
    // the fix belongs in this one file if it ever matters.
    return min + rand() % (max - min + 1);
}

}
