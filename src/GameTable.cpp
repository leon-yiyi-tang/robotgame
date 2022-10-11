#include "GameTable.h"
#include <cstddef>
#include <sstream>

#include "CmdException.h"
#include "NoRobotException.h"

#define MIN_X 0
#define MIN_Y 0

using namespace std;

namespace robotgame {


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
    return pos.x >= MIN_X && pos.x <= m_width
            && pos.y >= MIN_Y && pos.y <= m_height;
}

void GameTable::checkRobotPlaced()
{
    if (!hasRobotPlaced()){
        throw NoRobotException();
    }
}

Position GameTable::tryMoveRobot()
{
    int x = m_robot->getX();
    int y = m_robot->getY();
    DIRECTION dirc = m_robot->getFacingDirection();

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
        throw CmdException("Move", "Robot reached edge, cannot move furthur");
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
    ss << "Output:" << m_robot->getX() << "," << m_robot->getY() << "," << printDirection(m_robot->getFacingDirection());

    return ss.str();
}


}


