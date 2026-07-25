#pragma once

#include <string>

// Lightweight combat-facing view of a fighter, distinct from Character/Enemy:
// just enough (name, HP, attack, defense) for the turn-resolution loop to use,
// without either class needing to know about combat mechanics directly.
struct Combatant{
    std::string name;
    int hp;
    int attack;
    int defense;
};

class Character;

namespace combat{
    Combatant makePlayerCombatant(Character& player);
    Combatant makeMinotaurCombatant();

    // Reduces hp by damage and reports whether that KO'd the combatant.
    bool applyDamage(Combatant& target, int damage);
}
