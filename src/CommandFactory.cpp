#include "CommandFactory.h"

#include "StringHelper.h"
#include "Direction.h"
#include "CmdException.h"
#include "PlaceCommand.h"
#include "MoveCommand.h"
#include "RotateCommand.h"
#include "ReportCommand.h"


static const char* PLACE = "PLACE";
static const char* MOVE = "MOVE";
static const char* LEFT = "LEFT";
static const char* RIGHT = "RIGHT";
static const char* REPORT = "REPORT";

namespace robotgame {


CommandFactory::CommandFactory()
{

}

CommandPtr CommandFactory::parseCommand(const string &cmdStr)
{
    string text = helper::trim(cmdStr);

    size_t idx = text.find_first_of(helper::WHITESPACE);
    string cmdName = text.substr(0, idx);
    string argsStr;
    vector<string> argList;

    if (idx != string::npos) {
        string argsStr = helper::trim(text.substr(idx));
        helper::split(argsStr, argList, ',');
    }

    CmdType cmdType = translate(cmdName);
    if (cmdType == CMD_UNKNOWN) {
        throw CmdException("Invalid command", cmdStr.data());
    }

    switch (cmdType) {
    case CMD_PLACE: {
        if (argList.size() == 3) {
            int x = stoi(helper::trim(argList[0]));
            int y = stoi(helper::trim(argList[1]));
            DIRECTION direction = parseDirection(helper::trim(argList[2]));
            if (direction == DIRECTION_UNKNOWN ) {
                throw CmdException("Invalid command", cmdStr.data());
            }

            return CommandPtr(new PlaceCommand(x, y, direction));
        } else {
            throw CmdException("Invalid command", cmdStr.data());
        }
        break;
    }
    case CMD_MOVE: {
        return CommandPtr(new MoveCommand());
    }
    case CMD_LEFT: {
        return CommandPtr(new RotateCommand(false));
    }
    case CMD_RIGHT: {
        return CommandPtr(new RotateCommand(true));
    }
    case CMD_REPORT: {
        return CommandPtr(new ReportCommand());
    }

    default:
        break;
    }
    throw CmdException("Invalid command", cmdStr.data());
}

CommandFactory::CmdType CommandFactory::translate(const string &cmdName)
{
    if (cmdName.compare(PLACE) == 0) {
        return CMD_PLACE;
    } else if (cmdName.compare(MOVE) == 0) {
        return CMD_MOVE;
    } else if (cmdName.compare(LEFT) == 0) {
        return CMD_LEFT;
    } else if (cmdName.compare(RIGHT) == 0) {
        return CMD_RIGHT;
    } else if (cmdName.compare(REPORT) == 0) {
        return CMD_REPORT;
    }

    return CMD_UNKNOWN;
}

}
