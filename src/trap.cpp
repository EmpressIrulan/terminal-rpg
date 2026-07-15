#include "trap.h"

Trap::Trap(){
    type = TrapType::Spike;
}

TrapType Trap::getType(){
    return type;
}

void Trap::trigger(Character& target){
    if(type == TrapType::Spike){
        int damage = target.getMaxhp() / 10;
        target.dealDamage(damage);
    }
}
