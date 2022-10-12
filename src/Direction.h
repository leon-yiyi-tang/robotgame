#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

using namespace std;

namespace RobotGame {


enum DIRECTION {
    DIRECTION_EAST,
    DIRECTION_WEST,
    DIRECTION_SOUTH,
    DIRECTION_NORTH,
    DIRECTION_UNKNOWN = 255
};



const char* printDirection(DIRECTION direction);
DIRECTION parseDirection(const string& dirStr);

}

#endif // DIRECTION_H
