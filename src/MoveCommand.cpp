#include "MoveCommand.h"

#include "GameTable.h"

namespace RobotGame {


void MoveCommand::execute(GameTable &table) const
{
    table.moveRobot();
}

}


