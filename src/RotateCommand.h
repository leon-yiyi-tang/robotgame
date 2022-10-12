#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "Command.h"

namespace RobotGame {


class RotateCommand : public Command
{
public:
    RotateCommand(bool clockWise);

    // Command interface
    CmdType getType() const {
        return clockWise ? CMD_RIGHT : CMD_LEFT;
    }
    void execute(GameTable &table) const;
    string toString() const;


private:
    bool clockWise;
};

}

#endif // ROTATECOMMAND_H
