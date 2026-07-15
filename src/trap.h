#pragma once

#include "character.h"

enum class TrapType { Spike };

class Trap{
    private:
        TrapType type;

    public:
        Trap();

        TrapType getType();
        void trigger(Character& target);
};
