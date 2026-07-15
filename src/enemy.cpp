#include "enemy.h"

Enemy::Enemy(EnemyType type){
    this->type = type;

    if(type == EnemyType::GiantRat){
        name = "Giant Rat";
        strength = 0;
        dodge = 0;
        maxhp = 5;
        currentHp = 5;
        goldDrop = 1;
    }
}

std::string Enemy::getName(){
    return name;
}

int Enemy::getStrength(){
    return strength;
}

int Enemy::getDodge(){
    return dodge;
}

int Enemy::getMaxhp(){
    return maxhp;
}

int Enemy::getCurrentHp(){
    return currentHp;
}

int Enemy::getGoldDrop(){
    return goldDrop;
}

void Enemy::dealDamage(int damage){
    currentHp = currentHp - damage;
}

bool Enemy::checkAlive(){
    if(currentHp <= 0){
        return false;
    }
    else{
        return true;
    }
}
