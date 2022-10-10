
#include "Direction.h"

static const char* EAST = "EAST";
static const char* WEST = "WEST";
static const char* SOUTH = "SOUTH";
static const char* NORTH = "NORTH";
static const char* UNKNOWN = "UNKNOWN";

const char* printDirection(DIRECTION direction)
{
    switch (direction) {
    case DIRECTION_EAST:
        return EAST;
    case DIRECTION_WEST:
        return WEST;
    case DIRECTION_SOUTH:
        return SOUTH;
    case DIRECTION_NORTH:
        return NORTH;
    case DIRECTION_UNKNOWN:
        return UNKNOWN;
    default:
        break;
    }

    return "UNKNOWN";
}

DIRECTION parseDirection(const string& dirStr) {

    if (dirStr.compare(EAST) == 0) {
        return DIRECTION_EAST;
    } else if (dirStr.compare(WEST) == 0) {
        return DIRECTION_WEST;
    } else if (dirStr.compare(WEST) == 0) {
        return DIRECTION_WEST;
    } else if (dirStr.compare(SOUTH) == 0) {
        return DIRECTION_SOUTH;
    } else if (dirStr.compare(NORTH) == 0) {
        return DIRECTION_NORTH;
    }

    return DIRECTION_UNKNOWN;
}
