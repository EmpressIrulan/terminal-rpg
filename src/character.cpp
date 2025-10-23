#include "character.h"

Character::Character(int clss){
    if (clss = 0) {
        strength = 0;
        dodge = 0;
        maxhp = 10;
        reason = 0;
        persuasion = 0;
        currentHp = 10;
    }
}

void Character::dealDamage(int damage){
    currentHp = currentHp - damage;
}

void Character::heal(int heal){
    currentHp = currentHp + heal;
}

void Character::changeStrength(int change){
    strength = strength + change;
}

void Character::changeDoge(int change){
    dodge = dodge + change;
}

int Character::getStrength(){
    return strength;
}