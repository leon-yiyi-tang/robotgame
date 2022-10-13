#include "RotateCommand.h"

#include <sstream>
#include "GameTable.h"

namespace RobotGame {


    RotateCommand::RotateCommand(bool clockWise)
            : clockWise(clockWise) {

    }

    void RotateCommand::execute(GameTable &table) const {
        table.rotateRobot(clockWise);
    }

    string RotateCommand::toString() const {
        stringstream ss;
        ss << "Rotate : " << (clockWise ? "right" : "left");

        return ss.str();
    }

}
