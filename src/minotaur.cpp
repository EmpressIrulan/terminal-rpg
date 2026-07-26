#include "minotaur.h"

Minotaur::Minotaur(){
    name = "Minotaur";
    strength = 4;
    dodge = 1;
    maxhp = 20;
    currentHp = 20;
    distance = MINOTAUR_STARTING_DISTANCE;
}

std::string Minotaur::getName(){
    return name;
}

int Minotaur::getStrength(){
    return strength;
}

int Minotaur::getDodge(){
    return dodge;
}

int Minotaur::getMaxhp(){
    return maxhp;
}

int Minotaur::getCurrentHp(){
    return currentHp;
}

int Minotaur::getDistance(){
    return distance;
}

void Minotaur::changeDistance(int change){
    distance = distance + change;
    if(distance < 0){
        distance = 0;
    }
}

void Minotaur::dealDamage(int damage){
    currentHp = currentHp - damage;
}

bool Minotaur::checkAlive(){
    if(currentHp <= 0){
        return false;
    }
    else{
        return true;
    }
}

bool Minotaur::checkCaughtPlayer(){
    return distance <= 0;
}
