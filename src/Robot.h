#ifndef ROBOT_H
#define ROBOT_H

#include <memory>

#include "Direction.h"
#include "Position.h"

using namespace std;

namespace RobotGame {

class Robot
{
public:
    Robot(int x, int y, DIRECTION direction);

    DIRECTION getFacingDirection() const;
    void setFacingDirection(DIRECTION newFacingDirection);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

    Position getPosition() const {
        return position;
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
    DIRECTION facingDirection;
    Position position;
};

typedef unique_ptr<Robot> RobotPtr;

}

#endif // ROBOT_H
