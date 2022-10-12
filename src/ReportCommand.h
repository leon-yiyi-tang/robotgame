#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include "Command.h"

namespace RobotGame {


class ReportCommand : public Command
{
public:
    ReportCommand();
    // Command interface
    CmdType getType() const {
        return CMD_REPORT;
    }
    void execute(GameTable &table) const;

};

}

#endif // REPORTCOMMAND_H
