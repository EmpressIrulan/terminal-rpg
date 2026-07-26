#pragma once

// How many rooms behind the player the Minotaur starts at game start.
const int MINOTAUR_STARTING_DISTANCE = 5;

// The ticking clock: how many rooms behind the player the Minotaur (an
// ordinary Enemy of type EnemyType::Minotaur) currently is. Distance closes
// as the player takes actions (fighting, buying, failing to find a secret
// door). Finding a secret door is the only thing that buys the player more
// distance. Once distance reaches zero, the Minotaur has caught up.
class MinotaurClock{
    private:
        int distance;

    public:
        MinotaurClock();

        int getDistance();
        void changeDistance(int change);

        bool checkCaughtPlayer();
};
