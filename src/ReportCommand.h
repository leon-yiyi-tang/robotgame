#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include "Command.h"

class ReportCommand : public Command
{
public:
    ReportCommand();
    // Command interface
    void visit(GameTable &table) const;

};

#endif // REPORTCOMMAND_H
