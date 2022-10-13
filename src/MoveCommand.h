#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"

namespace RobotGame {

    class MoveCommand : public Command {
    public:
        MoveCommand() = default;

        CmdType getType() const {
            return CMD_MOVE;
        }

        void execute(GameTable &table) const;
    };

}

#endif // MOVECOMMAND_H
