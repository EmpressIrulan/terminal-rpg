#include <iostream>
#include "character.h"
#include "room.h"
#include "encounter.h"
#include "rng.h"
#include "combatant.h"
#include "minotaur.h"
#include "gui.h"

int main(){
    rng::seed();

    Character player;
    gui::displayStats(player);

    MinotaurClock minotaurClock;

    while(true){
        Room room;

        std::cout << std::endl;
        minotaurClock.changeDistance(gui::examineWalls(room));

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

            trap.trigger(player);
            std::cout << "Current HP: " << player.getCurrentHp() << "/" << player.getMaxhp() << std::endl;

            if(!player.checkAlive()){
                std::cout << "You have been defeated. Game over." << std::endl;
                return 0;
            }
        }
        else if(encounter.getType() == EncounterType::Shop){
            std::cout << "Shop" << std::endl;
            Shop& shop = encounter.getShop();
            if(gui::promptShopPurchase(shop, player)){
                minotaurClock.changeDistance(-1);
            }
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

            minotaurClock.changeDistance(-1);
            if(!combat::resolveEncounter(player, enemy)){
                std::cout << "You have been defeated. Game over." << std::endl;
                return 0;
            }
        }

        std::cout << std::endl;
        std::cout << "The Minotaur is " << minotaurClock.getDistance() << " rooms behind you." << std::endl;

        if(minotaurClock.checkCaughtPlayer()){
            std::cout << "The Minotaur has caught up to you!" << std::endl;
            std::cout << std::endl;

            Enemy minotaur(EnemyType::Minotaur);
            if(!combat::resolveEncounter(player, minotaur)){
                std::cout << "You have been defeated. Game over." << std::endl;
                return 0;
            }

            std::cout << "You have defeated the Minotaur! You win!" << std::endl;
            return 0;
        }

        std::optional<Direction> choice = gui::promptMove(room);
        if(!choice.has_value()){
            std::cout << "Farewell, adventurer." << std::endl;
            return 0;
        }
    }
}
