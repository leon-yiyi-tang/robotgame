#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "Command.h"

class RotateCommand : public Command
{
public:
    RotateCommand(bool clockWise);

    // Command interface
    void visit(GameTable &table) const;
    string toString() const;


private:
    bool m_clockWise;
};

#endif // ROTATECOMMAND_H
