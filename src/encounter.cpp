#include "encounter.h"
#include <cstdlib>

Encounter::Encounter() : enemy(EnemyType::GiantRat){
    int presenceRoll = rand() % 100;

    if(presenceRoll >= ENCOUNTER_CHANCE){
        type = EncounterType::Empty;
        return;
    }

    int typeRoll = rand() % ENCOUNTER_CHANCE;

    if(typeRoll < TRAP_CHANCE){
        type = EncounterType::Trap;
    }
    else if(typeRoll < TRAP_CHANCE + SHOP_CHANCE){
        type = EncounterType::Shop;
    }
    else{
        type = EncounterType::Enemy;
    }
}

EncounterType Encounter::getType(){
    return type;
}

Trap& Encounter::getTrap(){
    return trap;
}

Shop& Encounter::getShop(){
    return shop;
}

Enemy& Encounter::getEnemy(){
    return enemy;
}
