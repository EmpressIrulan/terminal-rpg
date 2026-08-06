#pragma once

#include <optional>
#include "character.h"
#include "room.h"
#include "shop.h"

// Minimal text interface for the game loop: printing room state and reading
// the player's choice of options from stdin.
namespace gui{
    void displayStats(Character& player);

    // Prints each wall's status, revealing secret doors on solid walls.
    // Returns the net minotaur-distance change from examining them: +1 per
    // secret door found, -1 per solid wall searched with none, 0 for open
    // walls.
    int examineWalls(Room& room);

    // Offers the shop's equipment as a numbered menu, plus a skip option,
    // and buys whatever the player picks. Returns whether a purchase was
    // made.
    bool promptShopPurchase(Shop& shop, Character& player);

    // Lists the room's open walls as a numbered menu, plus a Quit option.
    // Returns the chosen Direction, or std::nullopt if the player quit or
    // input ended.
    std::optional<Direction> promptMove(Room& room);
}
