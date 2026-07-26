#include <iostream>
#include "character.h"
#include "room.h"
#include "encounter.h"
#include "rng.h"
#include "combatant.h"
#include "minotaur.h"

int main(){
    rng::seed();

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
    Minotaur minotaur;

    std::cout << std::endl;

    std::cout << "North wall: ";
    if(room.getWallType(Direction::North) == WallType::Wall){
        std::cout << "Wall";
        if(room.checkSecretDoor(Direction::North)){
            std::cout << " (secret door!)";
            minotaur.changeDistance(1);
        }
        else{
            minotaur.changeDistance(-1);
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
            minotaur.changeDistance(1);
        }
        else{
            minotaur.changeDistance(-1);
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
            minotaur.changeDistance(1);
        }
        else{
            minotaur.changeDistance(-1);
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
            minotaur.changeDistance(1);
        }
        else{
            minotaur.changeDistance(-1);
        }
    }
    else{
        std::cout << "Room";
    }
    std::cout << std::endl;

    std::cout << std::endl;

    Encounter& encounter = room.getEncounter();

    std::cout << "Encounter: ";
    if(encounter.getType() == EncounterType::Empty){
        std::cout << "Empty" << std::endl;
    }
    else if(encounter.getType() == EncounterType::Trap){
        std::cout << "Trap" << std::endl;
        Trap& trap = encounter.getTrap();
        std::cout << "Trap type: ";
        if(trap.getType() == TrapType::Spike){
            std::cout << "Spike";
        }
        std::cout << std::endl;
    }
    else if(encounter.getType() == EncounterType::Shop){
        std::cout << "Shop" << std::endl;
        std::cout << "Equipment price: " << EQUIPMENT_PRICE << " gold" << std::endl;
    }
    else{
        std::cout << "Enemy" << std::endl;
        Enemy& enemy = encounter.getEnemy();
        std::cout << "Enemy name: " << enemy.getName() << std::endl;
        std::cout << "Enemy strength: " << enemy.getStrength() << std::endl;
        std::cout << "Enemy dodge: " << enemy.getDodge() << std::endl;
        std::cout << "Enemy HP: " << enemy.getCurrentHp() << "/" << enemy.getMaxhp() << std::endl;
        std::cout << "Enemy gold drop: " << enemy.getGoldDrop() << std::endl;

        std::cout << std::endl;

        minotaur.changeDistance(-1);
        if(!combat::resolveEncounter(player, enemy)){
            std::cout << "You have been defeated. Game over." << std::endl;
            return 0;
        }
    }

    std::cout << std::endl;

    std::cout << "The Minotaur is " << minotaur.getDistance() << " rooms behind you." << std::endl;

    if(minotaur.checkCaughtPlayer()){
        std::cout << "The Minotaur has caught up to you!" << std::endl;
        std::cout << std::endl;

        if(!combat::resolveMinotaurEncounter(player, minotaur)){
            std::cout << "You have been defeated. Game over." << std::endl;
            return 0;
        }
    }

    return 0;
}
