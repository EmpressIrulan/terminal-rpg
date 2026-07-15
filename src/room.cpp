#include "room.h"
#include <cstdlib>

const int WALL_TYPE_THRESHOLD = 50;      // roll below this -> Wall, else Room
const int SECRET_DOOR_CHANCE = 25;       // percent chance a Wall-type wall hides a secret door

Room::Room(){
    northWall = generateWall();
    southWall = generateWall();
    eastWall = generateWall();
    westWall = generateWall();
}

Wall Room::generateWall(){
    Wall wall;
    int typeRoll = rand() % 100;

    if(typeRoll < WALL_TYPE_THRESHOLD){
        wall.type = WallType::Wall;
    }
    else{
        wall.type = WallType::Room;
    }

    if(wall.type == WallType::Wall){
        wall.hasSecretDoor = (rand() % 100) < SECRET_DOOR_CHANCE;
    }
    else{
        wall.hasSecretDoor = false;
    }

    wall.discovered = false;
    return wall;
}

Wall& Room::getWall(Direction direction){
    if(direction == Direction::North){
        return northWall;
    }
    else if(direction == Direction::South){
        return southWall;
    }
    else if(direction == Direction::East){
        return eastWall;
    }
    else{
        return westWall;
    }
}

WallType Room::getWallType(Direction direction){
    return getWall(direction).type;
}

bool Room::checkSecretDoor(Direction direction){
    Wall& wall = getWall(direction);
    wall.discovered = true;
    return wall.hasSecretDoor;
}
