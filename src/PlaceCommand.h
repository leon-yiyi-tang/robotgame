#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include "Command.h"
#include "Direction.h"

namespace RobotGame {

    class PlaceCommand : public Command {
    public:
        PlaceCommand(int x, int y, DIRECTION direction);

        // Command interface
        CmdType getType() const {
            return CMD_PLACE;
        }

        void execute(GameTable &table) const;

        inline int getX() const {
            return x;
        }

        inline int getY() const {
            return y;
        }

        inline DIRECTION getDirection() const {
            return direction;
        }

    private:
        int x;
        int y;
        DIRECTION direction;
    };

}

#endif // PLACECOMMAND_H
