#include "character.h"

Character::Character(){
        strength = 0;
        dodge = 0;
        maxhp = 10;
        reason = 0;
        persuasion = 0;
        currentHp = 10;
        gold = 0;
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

void Character::changeDodge(int change){
    dodge = dodge + change;
}

void Character::changeReason(int change){
    reason = reason + change;
}

void Character::changePersuasion(int change){
    persuasion = persuasion + change;
}

void Character::changeMaxHp(int change){
    maxhp = maxhp + change;
}

void Character::changeGold(int change){
    gold = gold + change;
}

int Character::getStrength(){
    return strength;
}

int Character::getDodge(){
    return dodge;
}

int Character::getMaxhp(){
    return maxhp;
}

int Character::getReason(){
    return reason;
}

int Character::getPersuasion(){
    return persuasion;
}

int Character::getCurrentHp(){
    return currentHp;
}

int Character::getGold(){
    return gold;
}

bool Character::checkAlive(){
    if(currentHp <= 0){
        return false;
    }
    else{
        return true;
    }
}