#include "PlaceCommand.h"
#include "GameTable.h"

namespace RobotGame {


    PlaceCommand::PlaceCommand(int x, int y, DIRECTION direction)
            : x(x), y(y), direction(direction) {

    }

    void PlaceCommand::execute(GameTable &table) const {
        table.placeRobot(x, y, direction);
    }

}
