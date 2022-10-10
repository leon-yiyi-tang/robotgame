#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>

using namespace std;




class GameTable;

class Command
{
public:
    virtual ~Command(){}
    virtual void visit(GameTable& table) const = 0;
    virtual bool isPlaceCommand() const {
        return false;
    }
};

typedef unique_ptr<Command> CommandPtr;

#endif // COMMAND_H
