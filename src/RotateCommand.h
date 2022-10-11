#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "Command.h"

namespace robotgame {


class RotateCommand : public Command
{
public:
    RotateCommand(bool clockWise);

    // Command interface
    CmdType getType() const {
        return m_clockWise ? CMD_RIGHT: CMD_LEFT;
    }
    void visit(GameTable &table) const;
    string toString() const;


private:
    bool m_clockWise;
};

}

#endif // ROTATECOMMAND_H
