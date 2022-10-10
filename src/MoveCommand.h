#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"

namespace robotgame {


class MoveCommand : public Command
{
public:
    MoveCommand();

    void visit(GameTable& table) const;

};

}

#endif // MOVECOMMAND_H
