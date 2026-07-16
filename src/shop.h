#pragma once

#include "character.h"

enum class EquipmentType { Sword, Armour, Book, FluffyCoat };

const int EQUIPMENT_PRICE = 3;

class Shop{
    public:
        bool buy(Character& player, EquipmentType item);
};
