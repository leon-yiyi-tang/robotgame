#include "MoveCommand.h"

#include "GameTable.h"

MoveCommand::MoveCommand()
{

}

void MoveCommand::visit(GameTable &table) const
{
    table.moveRobot();
}
