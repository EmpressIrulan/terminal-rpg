#include "minotaur.h"

MinotaurClock::MinotaurClock(){
    distance = MINOTAUR_STARTING_DISTANCE;
}

int MinotaurClock::getDistance(){
    return distance;
}

void MinotaurClock::changeDistance(int change){
    distance = distance + change;
    if(distance < 0){
        distance = 0;
    }
}

bool MinotaurClock::checkCaughtPlayer(){
    return distance <= 0;
}
