#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include "Command.h"
#include "Direction.h"

namespace robotgame {


class PlaceCommand : public Command
{
public:
    PlaceCommand(int x, int y, DIRECTION direction);

    // Command interface
    CmdType getType() const {
        return CMD_PLACE;
    }
    void visit(GameTable &table) const;

    inline int getX() const {
        return m_x;
    }
    inline int getY() const {
        return m_y;
    }

    inline DIRECTION getDirection() const {
        return m_direction;
    }

private:
    int m_x;
    int m_y;
    DIRECTION m_direction;
};

}

#endif // PLACECOMMAND_H
