#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <memory>

#include "Robot.h"

using namespace std;

namespace robotgame {


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
        return m_robot;
    }

private:
    void checkRobotPlaced();

private:
    int m_width;
    int m_height;
    RobotPtr m_robot;

};

typedef unique_ptr<GameTable> GameTablePtr;

}

#endif // GAMETABLE_H
