#pragma once

#include "encounter.h"

enum class WallType { Wall, Room };
enum class Direction { North, South, East, West };

// Thrown by Room's constructor when all four walls roll solid, leaving no exit.
// main.cpp catches this and rerolls rather than generating an unplayable room.
struct DeadEndRoom {};

struct Wall{
    WallType type;
    bool hasSecretDoor;
    bool discovered;
};

class Room{
    private:
        Wall northWall;
        Wall southWall;
        Wall eastWall;
        Wall westWall;
        Encounter encounter;

        Wall& getWall(Direction direction);
        Wall generateWall();

    public:
        Room();

        WallType getWallType(Direction direction);
        bool checkSecretDoor(Direction direction);
        Encounter& getEncounter();
};
