#include <iostream>
#include "character.h"

int main(){
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

    return 0;
}
