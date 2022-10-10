#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include "Command.h"
#include "Direction.h"

class PlaceCommand : public Command
{
public:
    PlaceCommand(int x, int y, DIRECTION direction);

    // Command interface
    void visit(GameTable &table) const;
    bool isPlaceCommand() const {
        return true;
    };

private:
    int m_x;
    int m_y;
    DIRECTION m_direction;
};

#endif // PLACECOMMAND_H
