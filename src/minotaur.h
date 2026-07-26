#pragma once

#include <string>

// How many rooms behind the player the Minotaur starts at game start.
const int MINOTAUR_STARTING_DISTANCE = 5;

// The Minotaur is the ticking clock: it starts some distance behind the
// player and closes in as the player takes actions (fighting, buying,
// failing to find a secret door). Finding a secret door is the only thing
// that buys the player more distance. Once distance reaches zero, the
// Minotaur has caught up and combat begins.
class Minotaur{
    private:
        std::string name;
        int strength;
        int dodge;
        int maxhp;
        int currentHp;
        int distance;

    public:
        Minotaur();

        std::string getName();
        int getStrength();
        int getDodge();
        int getMaxhp();
        int getCurrentHp();
        int getDistance();

        void changeDistance(int change);
        void dealDamage(int damage);

        bool checkAlive();
        bool checkCaughtPlayer();
};
