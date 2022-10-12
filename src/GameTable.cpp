#include "GameTable.h"
#include <cstddef>
#include <sstream>

#include "CmdException.h"
#include "NoRobotException.h"

#define MIN_X 0
#define MIN_Y 0

using namespace std;

namespace RobotGame {


GameTable::GameTable(int width, int height)
    : width(width), height(height)
{
}

bool GameTable::hasRobotPlaced() const
{
    return !!robot;
}

bool GameTable::isValidPosition(const Position &pos)
{
    return pos.x >= MIN_X && pos.x <= width
            && pos.y >= MIN_Y && pos.y <= height;
}

void GameTable::checkRobotPlaced()
{
    if (!hasRobotPlaced()){
        throw NoRobotException();
    }
}

Position GameTable::tryMoveRobot()
{
    int x = robot->getX();
    int y = robot->getY();
    DIRECTION dirc = robot->getFacingDirection();

    switch (dirc) {
    case DIRECTION_EAST:
        x = x + 1;
        break;
    case DIRECTION_SOUTH:
        y = y - 1;
        break;
    case DIRECTION_WEST:
        x = x - 1;
        break;
    case DIRECTION_NORTH:
        y = y + 1;
        break;
    default:
        break;
    }

    return Position(x, y);
}

void GameTable::moveRobot()
{
    checkRobotPlaced();

    Position newPos = tryMoveRobot();
    if (!isValidPosition(newPos)) {
        throw CmdException("Move", "Robot reached edge, cannot move further");
    } else {
        robot->setPosition(newPos);
    }
}

void GameTable::placeRobot(int x, int y, DIRECTION direction)
{
    Position pos(x, y);
    if (!isValidPosition(pos)) {
        throw CmdException("Place", "Invalid Position");
    } else if (direction == DIRECTION_UNKNOWN) {
        throw CmdException("Place", "Invalid direction");
    } else {
        if (!robot) {
            robot = make_unique<Robot>(x, y, direction);
        } else {
            robot->place(x, y, direction);
        }
    }
}

void GameTable::rotateRobot(bool clockWise)
{
    checkRobotPlaced();
    robot->rotate(clockWise);
}

string GameTable::reportStatus() const
{
    if (!hasRobotPlaced()) {
        return "Robot is not placed yet";
    }

    stringstream ss;
    ss << "Output:" << robot->getX() << "," << robot->getY() << "," << printDirection(robot->getFacingDirection());

    return ss.str();
}


}


