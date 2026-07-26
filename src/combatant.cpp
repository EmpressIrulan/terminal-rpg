#include "combatant.h"
#include "character.h"
#include "enemy.h"
#include "rng.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace combat{

Combatant makePlayerCombatant(Character& player){
    Combatant combatant;
    combatant.name = "Player";
    combatant.hp = player.getCurrentHp();
    combatant.attack = player.getStrength();
    combatant.defense = player.getDodge();
    return combatant;
}

Combatant makeEnemyCombatant(Enemy& enemy){
    Combatant combatant;
    combatant.name = enemy.getName();
    combatant.hp = enemy.getCurrentHp();
    combatant.attack = enemy.getStrength();
    combatant.defense = enemy.getDodge();
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
        std::cout << attacker.name << " attacks " << defender.name << " and misses!" << std::endl;
        return false;
    }

    int damage = rng::rollRange(1, attacker.attack);
    bool koed = applyDamage(defender, damage);
    std::cout << attacker.name << " hits " << defender.name << " for " << damage << " damage!" << std::endl;
    return koed;
}

Combatant* runEncounter(Combatant& a, Combatant& b){
    while(true){
        if(resolveTurn(a, b)){
            return &a;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if(resolveTurn(b, a)){
            return &b;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

bool resolveEncounter(Character& player, Enemy& enemy){
    Combatant playerCombatant = makePlayerCombatant(player);
    Combatant enemyCombatant = makeEnemyCombatant(enemy);

    std::cout << "Combat: " << playerCombatant.name << " vs " << enemyCombatant.name << std::endl;
    Combatant* winner = runEncounter(playerCombatant, enemyCombatant);

    player.dealDamage(player.getCurrentHp() - playerCombatant.hp);
    enemy.dealDamage(enemy.getCurrentHp() - enemyCombatant.hp);

    if(winner == &playerCombatant){
        std::cout << enemy.getName() << " is defeated! Gained " << enemy.getGoldDrop() << " gold." << std::endl;
        player.changeGold(enemy.getGoldDrop());
    }

    return player.checkAlive();
}

}
