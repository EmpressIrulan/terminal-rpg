#pragma once

#include "trap.h"
#include "shop.h"
#include "enemy.h"

const int TRAP_CHANCE = 10;
const int SHOP_CHANCE = 10;
const int ENEMY_CHANCE = 30;
const int ENCOUNTER_CHANCE = TRAP_CHANCE + SHOP_CHANCE + ENEMY_CHANCE;

enum class EncounterType { Empty, Trap, Shop, Enemy };

class Encounter{
    private:
        EncounterType type;
        Trap trap;
        Shop shop;
        Enemy enemy;

    public:
        Encounter();

        EncounterType getType();
        Trap& getTrap();
        Shop& getShop();
        Enemy& getEnemy();
};
