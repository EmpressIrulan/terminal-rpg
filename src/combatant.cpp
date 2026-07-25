#include "combatant.h"
#include "character.h"
#include "rng.h"

namespace combat{

Combatant makePlayerCombatant(Character& player){
    Combatant combatant;
    combatant.name = "Player";
    combatant.hp = player.getCurrentHp();
    combatant.attack = player.getStrength();
    combatant.defense = player.getDodge();
    return combatant;
}

// The minotaur isn't a full Enemy yet (see issue #7), so its combat stats are
// hardcoded here until that lands.
Combatant makeMinotaurCombatant(){
    Combatant combatant;
    combatant.name = "Minotaur";
    combatant.hp = 20;
    combatant.attack = 4;
    combatant.defense = 1;
    return combatant;
}

bool applyDamage(Combatant& target, int damage){
    target.hp = target.hp - damage;
    return target.hp <= 0;
}

bool resolveTurn(Combatant& attacker, Combatant& defender){
    // Hit chance shifts with the attack/defense gap, still clamped by
    // rollChance so neither side is ever a guaranteed hit or guaranteed miss.
    int hitChance = 50 + (attacker.attack - defender.defense) * 10;
    if(!rng::rollChance(hitChance)){
        return false;
    }

    int damage = rng::rollRange(1, attacker.attack);
    return applyDamage(defender, damage);
}

Combatant* runEncounter(Combatant& a, Combatant& b){
    while(true){
        if(resolveTurn(a, b)){
            return &a;
        }
        if(resolveTurn(b, a)){
            return &b;
        }
    }
}

}
