#include "PlaceCommand.h"
#include "GameTable.h"

namespace robotgame {


PlaceCommand::PlaceCommand(int x, int y, DIRECTION direction)
    :m_x(x),m_y(y),m_direction(direction)
{

}

void PlaceCommand::visit(GameTable &table) const
{
    table.placeRobot(m_x, m_y, m_direction);
}

}
