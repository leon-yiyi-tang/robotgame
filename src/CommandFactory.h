#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"

namespace robotgame {


class CommandFactory
{
public:

    CommandFactory();

    static CommandPtr parseCommand(const string& cmdStr);
    static Command::CmdType translate(const string& cmdName);

};

}

#endif // COMMANDFACTORY_H
