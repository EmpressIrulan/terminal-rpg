#include "encounter.h"
#include "rng.h"

Encounter::Encounter() : enemy(EnemyType::GiantRat){
    if(!rng::rollChance(ENCOUNTER_CHANCE)){
        type = EncounterType::Empty;
        return;
    }

    // The encounter exists; this second roll picks which kind, so it spans the
    // encounter chances only rather than the full 100.
    int typeRoll = rng::rollRange(0, ENCOUNTER_CHANCE - 1);

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
