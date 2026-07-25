#include "combatant.h"
#include "character.h"

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

}
