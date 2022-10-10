#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"

class CommandFactory
{
public:
    enum CmdType {
        CMD_PLACE,
        CMD_MOVE,
        CMD_LEFT,
        CMD_RIGHT,
        CMD_REPORT,
        CMD_UNKNOWN = 255
    };
    CommandFactory();

    static CommandPtr parseCommand(const string& cmdStr);
    static CmdType translate(const string& cmdName);

};

#endif // COMMANDFACTORY_H
