#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "room.h"

int main(){
    srand(time(nullptr));

    Character player;

    std::cout << "Strength: " << player.getStrength() << std::endl;
    std::cout << "Dodge: " << player.getDodge() << std::endl;
    std::cout << "Max HP: " << player.getMaxhp() << std::endl;
    std::cout << "Reason: " << player.getReason() << std::endl;
    std::cout << "Persuasion: " << player.getPersuasion() << std::endl;
    std::cout << "Current HP: " << player.getCurrentHp() << std::endl;

    if(player.checkAlive()){
        std::cout << "Alive: yes" << std::endl;
    }
    else{
        std::cout << "Alive: no" << std::endl;
    }

    Room room;

    std::cout << std::endl;

    std::cout << "North wall: ";
    if(room.getWallType(Direction::North) == WallType::Wall){
        std::cout << "Wall";
        if(room.checkSecretDoor(Direction::North)){
            std::cout << " (secret door!)";
        }
    }
    else{
        std::cout << "Room";
    }
    std::cout << std::endl;

    std::cout << "South wall: ";
    if(room.getWallType(Direction::South) == WallType::Wall){
        std::cout << "Wall";
        if(room.checkSecretDoor(Direction::South)){
            std::cout << " (secret door!)";
        }
    }
    else{
        std::cout << "Room";
    }
    std::cout << std::endl;

    std::cout << "East wall: ";
    if(room.getWallType(Direction::East) == WallType::Wall){
        std::cout << "Wall";
        if(room.checkSecretDoor(Direction::East)){
            std::cout << " (secret door!)";
        }
    }
    else{
        std::cout << "Room";
    }
    std::cout << std::endl;

    std::cout << "West wall: ";
    if(room.getWallType(Direction::West) == WallType::Wall){
        std::cout << "Wall";
        if(room.checkSecretDoor(Direction::West)){
            std::cout << " (secret door!)";
        }
    }
    else{
        std::cout << "Room";
    }
    std::cout << std::endl;

    return 0;
}
