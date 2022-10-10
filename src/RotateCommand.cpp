#include "RotateCommand.h"

#include <sstream>
#include "GameTable.h"

namespace robotgame {


RotateCommand::RotateCommand(bool clockWise)
    :m_clockWise(clockWise)
{

}


void RotateCommand::visit(GameTable &table) const
{
    table.rotateRobot(m_clockWise);
}


string RotateCommand::toString() const
{
    stringstream ss;
    ss << "Rotate : " << (m_clockWise ? "right":"left");

    return ss.str() ;
}

}
