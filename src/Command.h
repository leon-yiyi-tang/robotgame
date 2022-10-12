#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>

using namespace std;


namespace RobotGame {

class GameTable;

class Command
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

public:
    virtual ~Command(){}
    virtual CmdType getType() const = 0;
    virtual void execute(GameTable& table) const = 0;
};

typedef unique_ptr<Command> CommandPtr;

}



#endif // COMMAND_H
