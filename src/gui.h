#pragma once

#include <optional>
#include "character.h"
#include "room.h"
#include "shop.h"
#include "minotaur.h"

// Minimal text interface for the game loop: printing room state and reading
// the player's choice of options from stdin.
namespace gui{
    void displayStats(Character& player);

    // Prints each wall's status, revealing secret doors on solid walls, and
    // applies each wall's minotaur-distance change as its own call to
    // minotaurClock.changeDistance: +1 per secret door found, -1 per solid
    // wall searched with none. Calling per-wall (rather than summing first)
    // matters because changeDistance clamps at zero, so a floor hit early in
    // the room doesn't erase credit for a secret door found later on.
    void examineWalls(Room& room, MinotaurClock& minotaurClock);

    // Offers the shop's equipment as a numbered menu, plus a skip option,
    // and buys whatever the player picks. Returns whether a purchase was
    // made.
    bool promptShopPurchase(Shop& shop, Character& player);

    // Lists the room's open walls as a numbered menu, plus a Quit option.
    // Returns the chosen Direction, or std::nullopt if the player quit or
    // input ended.
    std::optional<Direction> promptMove(Room& room);
}
