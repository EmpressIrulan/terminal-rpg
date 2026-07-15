#include "shop.h"

bool Shop::buy(Character& player, EquipmentType item){
    if(player.getGold() < EQUIPMENT_PRICE){
        return false;
    }

    player.changeGold(-EQUIPMENT_PRICE);

    if(item == EquipmentType::Sword){
        player.changeStrength(1);
    }
    else if(item == EquipmentType::Armour){
        player.changeDodge(1);
    }
    else if(item == EquipmentType::Book){
        player.changeReason(1);
    }
    else{
        player.changePersuasion(1);
    }

    return true;
}
