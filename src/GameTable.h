#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <memory>

#include "Robot.h"

using namespace std;

namespace RobotGame {


class GameTable
{
public:
    GameTable(int width, int height);

    bool hasRobotPlaced() const;
    bool isValidPosition(const Position& pos);
    Position tryMoveRobot();
    void moveRobot();
    void placeRobot(int x, int y, DIRECTION direction);
    void rotateRobot(bool clockWise);
    string reportStatus() const;
    const RobotPtr& getRobot() const {
        return robot;
    }

private:
    void checkRobotPlaced();

private:
    int width;
    int height;
    RobotPtr robot;

};

typedef unique_ptr<GameTable> GameTablePtr;

}

#endif // GAMETABLE_H
