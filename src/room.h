enum class WallType { Wall, Room };
enum class Direction { North, South, East, West };

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

        Wall& getWall(Direction direction);
        Wall generateWall();

    public:
        Room();

        WallType getWallType(Direction direction);
        bool checkSecretDoor(Direction direction);
};
