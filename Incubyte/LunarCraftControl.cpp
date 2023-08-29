#include <iostream>

enum class Direction {
    North,
    South,
    East,
    West,
    Up,
    Down
};

struct Spacecraft {
    int x;
    int y;
    int z;
    Direction facing;
};

void moveForward(Spacecraft &craft) {
    switch (craft.facing) {
        case Direction::North:
            craft.y++;
            break;
        case Direction::South:
            craft.y--;
            break;
        case Direction::East:
            craft.x++;
            break;
        case Direction::West:
            craft.x--;
            break;
        case Direction::Up:
            craft.z++;
            break;
        case Direction::Down:
            craft.z--;
            break;
    }
}

void moveBackward(Spacecraft &craft) {
    switch (craft.facing) {
        case Direction::North:
            craft.y--;
            break;
        case Direction::South:
            craft.y++;
            break;
        case Direction::East:
            craft.x--;
            break;
        case Direction::West:
            craft.x++;
            break;
        case Direction::Up:
            craft.z--;
            break;
        case Direction::Down:
            craft.z++;
            break;
    }
}

void turnLeft(Spacecraft &craft) {
    switch (craft.facing) {
        case Direction::North:
            craft.facing = Direction::West;
            break;
        case Direction::South:
            craft.facing = Direction::East;
            break;
        case Direction::East:
            craft.facing = Direction::North;
            break;
        case Direction::West:
            craft.facing = Direction::South;
            break;
        default:
            break;
    }
}

void turnRight(Spacecraft &craft) {
    switch (craft.facing) {
        case Direction::North:
            craft.facing = Direction::East;
            break;
        case Direction::South:
            craft.facing = Direction::West;
            break;
        case Direction::East:
            craft.facing = Direction::South;
            break;
        case Direction::West:
            craft.facing = Direction::North;
            break;
        default:
            break;
    }
}

void turnUp(Spacecraft &craft) {
    if (craft.facing == Direction::North || craft.facing == Direction::South) {
        craft.facing = Direction::Up;
    }
}

void turnDown(Spacecraft &craft) {
    if (craft.facing == Direction::North || craft.facing == Direction::South) {
        craft.facing = Direction::Down;
    }
}

int main() {
    Spacecraft craft;
    craft.x = 0;
    craft.y = 0;
    craft.z = 0;
    craft.facing = Direction::North;

    char commands[] = {'f', 'r', 'u', 'b', 'l'};

    for (char command : commands) {
        switch (command) {
            case 'f':
                moveForward(craft);
                break;
            case 'b':
                moveBackward(craft);
                break;
            case 'l':
                turnLeft(craft);
                break;
            case 'r':
                turnRight(craft);
                break;
            case 'u':
                turnUp(craft);
                break;
            case 'd':
                turnDown(craft);
                break;
            default:
                // Invalid command
                break;
        }
    }

    std::cout << "Final Position: (" << craft.x << ", " << craft.y << ", " << craft.z << ")\n";
    std::cout << "Final Direction: " << static_cast<int>(craft.facing) << std::endl;

    return 0;
}
