#include "Robot.h"

Robot::Robot(int x, int y, DIRECTION direction)
    :m_x(x), m_y(y), m_facingDirection(direction)
{

}

DIRECTION Robot::facingDirection() const
{
    return m_facingDirection;
}

void Robot::setFacingDirection(DIRECTION newFacingDirection)
{
    this->m_facingDirection = newFacingDirection;
}

int Robot::x() const
{
    return m_x;
}

void Robot::setX(int x)
{
    this->m_x = x;
}

int Robot::y() const
{
    return m_y;
}

void Robot::setY(int y)
{
    this->m_y = y;
}

void Robot::place(int x, int y, DIRECTION facingDirection)
{
    this->m_x = x;
    this->m_y = y;
    this->m_facingDirection = facingDirection;
}

void Robot::rotate(bool clockWise)
{
    DIRECTION direction = clockWise ? nextAntiClockWiseDirection(m_facingDirection)
                                    : nextAntiClockWiseDirection(m_facingDirection);
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

