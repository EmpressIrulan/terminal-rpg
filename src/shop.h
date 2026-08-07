#pragma once

#include "character.h"

enum class EquipmentType { Sword, Armour, Book, FluffyCoat };

const int EQUIPMENT_PRICE = 3;

// Thrown by Shop::buy when the player can't afford the item.
struct InsufficientGold {
    int price;
    int have;
};

class Shop{
    public:
        void buy(Character& player, EquipmentType item);
};
