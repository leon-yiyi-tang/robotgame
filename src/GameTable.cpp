#include "GameTable.h"
#include <cstddef>
#include <sstream>

#include "CmdException.h"
#include "NoRobotException.h"

using namespace std;

GameTable::GameTable(int width, int height)
    :m_width(width),m_height(height)
{
}

bool GameTable::hasRobotPlaced() const
{
    return !!m_robot;
}

bool GameTable::isValidPosition(const Position &pos)
{
    return pos.x >= 0 && pos.x <= m_width
            && pos.y >= 0 && pos.y <= m_height;
}

void GameTable::checkRobotPlaced()
{
    if (!hasRobotPlaced()){
        throw NoRobotException();
    }
}

Position GameTable::tryMoveRobot()
{
    int x = m_robot->x();
    int y = m_robot->y();
    DIRECTION dirc = m_robot->facingDirection();

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
        throw CmdException("Move", "Invalid Position");
    } else {
        m_robot->setPosition(newPos);
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
        m_robot = RobotPtr(new Robot(x, y, direction));
    }
}

void GameTable::rotateRobot(bool clockWise)
{
    checkRobotPlaced();
    m_robot->rotate(clockWise);
}

string GameTable::reportStatus() const
{
    if (!hasRobotPlaced()) {
        return "Robot is not placed yet";
    }

    stringstream ss;
    ss << "X:" << m_robot->x() << ", Y:" << m_robot->y() << ", F:" << printDirection(m_robot->facingDirection());

    return ss.str();
}

