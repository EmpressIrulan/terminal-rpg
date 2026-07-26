#pragma once

#include <string>

enum class EnemyType { GiantRat, Minotaur };

class Enemy{
    private:
        EnemyType type;
        std::string name;
        int strength;
        int dodge;
        int maxhp;
        int currentHp;
        int goldDrop;

    public:
        Enemy(EnemyType type);

        std::string getName();
        int getStrength();
        int getDodge();
        int getMaxhp();
        int getCurrentHp();
        int getGoldDrop();

        void dealDamage(int damage);
        bool checkAlive();
};
