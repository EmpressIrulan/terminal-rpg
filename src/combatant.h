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

    // One attacker's turn: rolls to hit defender using rng, and on a hit rolls
    // damage and applies it. Returns whether defender was KO'd.
    bool resolveTurn(Combatant& attacker, Combatant& defender);

    // Alternates resolveTurn(a, b) / resolveTurn(b, a) until one side is KO'd.
    // Returns a pointer to whichever Combatant is still standing.
    Combatant* runEncounter(Combatant& a, Combatant& b);
}
