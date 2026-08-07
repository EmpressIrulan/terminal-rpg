#include <iostream>
#include <limits>
#include "gui.h"

namespace {
    const Direction ALL_DIRECTIONS[] = { Direction::North, Direction::South, Direction::East, Direction::West };
    const char* DIRECTION_NAMES[] = { "North", "South", "East", "West" };
}

void gui::displayStats(Character& player){
    std::cout << "Strength: " << player.getStrength() << std::endl;
    std::cout << "Dodge: " << player.getDodge() << std::endl;
    std::cout << "Max HP: " << player.getMaxhp() << std::endl;
    std::cout << "Reason: " << player.getReason() << std::endl;
    std::cout << "Persuasion: " << player.getPersuasion() << std::endl;
    std::cout << "Current HP: " << player.getCurrentHp() << std::endl;
    std::cout << "Gold: " << player.getGold() << std::endl;
}

void gui::examineWalls(Room& room, MinotaurClock& minotaurClock){
    for(int i = 0; i < 4; i++){
        Direction direction = ALL_DIRECTIONS[i];
        std::cout << DIRECTION_NAMES[i] << " wall: ";

        if(room.getWallType(direction) == WallType::Wall){
            std::cout << "Wall";
            if(room.checkSecretDoor(direction)){
                std::cout << " (secret door!)";
                minotaurClock.changeDistance(1);
            }
            else{
                minotaurClock.changeDistance(-1);
            }
        }
        else{
            std::cout << "Room";
        }
        std::cout << std::endl;
    }
}

bool gui::promptShopPurchase(Shop& shop, Character& player){
    const EquipmentType items[] = { EquipmentType::Sword, EquipmentType::Armour, EquipmentType::Book, EquipmentType::FluffyCoat };
    const char* names[] = { "Sword (+1 Strength)", "Armour (+1 Dodge)", "Book (+1 Reason)", "Fluffy Coat (+1 Persuasion)" };

    std::cout << "Equipment price: " << EQUIPMENT_PRICE << " gold" << std::endl;
    std::cout << "Your gold: " << player.getGold() << std::endl;
    std::cout << "Options:" << std::endl;
    for(int i = 0; i < 4; i++){
        std::cout << "  " << (i + 1) << ") Buy " << names[i] << std::endl;
    }
    std::cout << "  0) Leave" << std::endl;

    while(true){
        std::cout << "> ";
        int choice;
        if(!(std::cin >> choice)){
            if(std::cin.eof()){
                return false;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice." << std::endl;
            continue;
        }
        if(choice == 0){
            return false;
        }
        if(choice >= 1 && choice <= 4){
            try{
                shop.buy(player, items[choice - 1]);
                std::cout << "Bought " << names[choice - 1] << "." << std::endl;
                return true;
            }
            catch(const InsufficientGold& e){
                std::cout << "Not enough gold. Need " << e.price << ", have " << e.have << "." << std::endl;
                return false;
            }
        }
        std::cout << "Invalid choice." << std::endl;
    }
}

std::optional<Direction> gui::promptMove(Room& room){
    Direction open[4];
    const char* labels[4];
    int openCount = 0;

    for(int i = 0; i < 4; i++){
        if(room.getWallType(ALL_DIRECTIONS[i]) == WallType::Room){
            open[openCount] = ALL_DIRECTIONS[i];
            labels[openCount] = DIRECTION_NAMES[i];
            openCount++;
        }
    }

    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    for(int i = 0; i < openCount; i++){
        std::cout << "  " << (i + 1) << ") Go " << labels[i] << std::endl;
    }
    std::cout << "  0) Quit" << std::endl;

    if(openCount == 0){
        std::cout << "There is no way out of this room." << std::endl;
    }

    while(true){
        std::cout << "> ";
        int choice;
        if(!(std::cin >> choice)){
            if(std::cin.eof()){
                return std::nullopt;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice." << std::endl;
            continue;
        }
        if(choice == 0){
            return std::nullopt;
        }
        if(choice >= 1 && choice <= openCount){
            return open[choice - 1];
        }
        std::cout << "Invalid choice." << std::endl;
    }
}
