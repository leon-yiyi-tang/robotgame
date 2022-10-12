#include "ReportCommand.h"

#include "GameTable.h"
#include <iostream>

namespace RobotGame {

ReportCommand::ReportCommand()
{

}


void ReportCommand::execute(GameTable &table) const
{
    std::cout << table.reportStatus() << std::endl;
}

}


