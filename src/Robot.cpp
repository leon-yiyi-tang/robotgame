#include "Robot.h"

namespace RobotGame {

Robot::Robot(int x, int y, DIRECTION direction)
    : position(x, y), facingDirection(direction)
{

}

DIRECTION Robot::getFacingDirection() const
{
    return facingDirection;
}

void Robot::setFacingDirection(DIRECTION newFacingDirection)
{
    this->facingDirection = newFacingDirection;
}

int Robot::getX() const
{
    return position.x;
}

void Robot::setX(int x)
{
    position.x = x;
}

int Robot::getY() const
{
    return position.y;
}

void Robot::setY(int y)
{
    position.y = y;
}

void Robot::place(int x, int y, DIRECTION facingDirection)
{
    this->position.x = x;
    this->position.y = y;
    this->facingDirection = facingDirection;
}

void Robot::rotate(bool clockWise)
{
    DIRECTION direction = clockWise ? nextClockWiseDirection(facingDirection)
                                    : nextAntiClockWiseDirection(facingDirection);
    setFacingDirection(direction);
}

DIRECTION Robot::nextClockWiseDirection(DIRECTION direction)
{
    switch (direction) {
    case DIRECTION_EAST:
        return DIRECTION_SOUTH;
    case DIRECTION_SOUTH:
        return DIRECTION_WEST;
    case DIRECTION_WEST:
        return DIRECTION_NORTH;
    case DIRECTION_NORTH:
        return DIRECTION_EAST;
    default:
        break;
    }

    return DIRECTION_UNKNOWN;
}

DIRECTION Robot::nextAntiClockWiseDirection(DIRECTION direction)
{
    switch (direction) {
    case DIRECTION_EAST:
        return DIRECTION_NORTH;
    case DIRECTION_SOUTH:
        return DIRECTION_EAST;
    case DIRECTION_WEST:
        return DIRECTION_SOUTH;
    case DIRECTION_NORTH:
        return DIRECTION_WEST;
    default:
        break;
    }

    return DIRECTION_UNKNOWN;
}

}
