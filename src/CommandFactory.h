#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <vector>

namespace RobotGame {


class CommandFactory
{
public:

    static CommandPtr parseCommand(const string& cmdStr);
    static Command::CmdType translate(const string& cmdName);

private:
    static CommandPtr parsePlaceCommand(const string& cmdStr, const std::vector<string>& argList);

};

}

#endif // COMMANDFACTORY_H
