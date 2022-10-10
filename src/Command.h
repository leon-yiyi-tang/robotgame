#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>

using namespace std;


namespace robotgame {

class GameTable;

class Command
{
public:
    virtual ~Command(){}
    virtual void visit(GameTable& table) const = 0;
};

typedef unique_ptr<Command> CommandPtr;

}



#endif // COMMAND_H
