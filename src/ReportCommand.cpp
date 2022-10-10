#include "ReportCommand.h"

#include "GameTable.h"
#include <iostream>

namespace robotgame {

ReportCommand::ReportCommand()
{

}


void ReportCommand::visit(GameTable &table) const
{
    std::cout << table.reportStatus() << std::endl;
}

}


