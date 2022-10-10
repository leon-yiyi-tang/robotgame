#include "MoveCommand.h"

#include "GameTable.h"

namespace robotgame {

MoveCommand::MoveCommand()
{

}

void MoveCommand::visit(GameTable &table) const
{
    table.moveRobot();
}

}


