#ifndef ROBOT_H
#define ROBOT_H

#include <memory>

#include "Direction.h"
#include "Position.h"

using namespace std;

class Robot
{
public:
    Robot(int x, int y, DIRECTION direction);

    DIRECTION facingDirection() const;
    void setFacingDirection(DIRECTION newFacingDirection);
    int x() const;
    void setX(int x);
    int y() const;
    void setY(int y);

    Position getPosition() const {
        return Position(m_x, m_y);
    }
    void setPosition(const Position& pos) {
        setX(pos.x);
        setY(pos.y);
    }

    void place(int x, int y, DIRECTION facingDirection);
    void rotate(bool clockWise);

private:
    DIRECTION nextClockWiseDirection(DIRECTION direction);
    DIRECTION nextAntiClockWiseDirection(DIRECTION direction);

private:
    DIRECTION m_facingDirection;
    int m_x;
    int m_y;
};

typedef unique_ptr<Robot> RobotPtr;

#endif // ROBOT_H
