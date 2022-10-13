#include <iostream>

#include "GameApp.h"
#include "CommandFactory.h"
#include <string.h>
#include <algorithm>

#include "CmdException.h"
#include "NoRobotException.h"

using namespace std;
using namespace RobotGame;

void printHelp(const char *appName) {
    cout << "Usage: " << appName << " [-h]  " << endl;
    cout << "\t\t" << "-h         print this help message " << endl;
    cout << "Supported Commands:" << endl;
    cout << "          QUIT          " << "  quit this program " << endl;
    cout << "          PLACE X,Y,F   " << "  place the robot in position (X,Y), facing direction F" << endl;
    cout << "                        " << "  available directions: NORTH, SOUTH, EAST or WEST" << endl;
    cout << "          MOVE          " << "  move the robot 1 step in its facing direction  " << endl;
    cout << "          LEFT          " << "  rotate the robot of 90 degrees in anti-clockwise direction  " << endl;
    cout << "          RIGHT         " << "  rotate the robot of 90 degrees in clockwise direction  " << endl;
    cout << "          REPORT        " << "  report the position and facing direction of the robot  " << endl;
}

bool bPrintHelp = false;

void parseArgs(int argc) {
    if (argc > 1) {
        bPrintHelp = true;
        return;
    }
}

#define QUIT "QUIT"

bool isQuitCmd(const string &cmd) {
    return cmd.compare(QUIT) == 0;
}

int main(int argc, char **argv) {
    parseArgs(argc);
    if (bPrintHelp) {
        printHelp(argv[0]);
        exit(0);
    }

    GameApp app;

    string line;
    do {
        cout << "Please enter a command:" << endl;
        getline(cin, line);
        if ((!cin) || isQuitCmd(line)) {
            break;
        }

        if (line.empty()) {
            continue;
        }

        try {
            CommandPtr pCmd = CommandFactory::parseCommand(line);
            if (pCmd) {
                app.processCommand(*pCmd);
            }
        } catch (NoRobotException e1) {
            cout << e1.what() << endl;
        } catch (CmdException cmdException) {
            cout << cmdException.toString() << endl;
        } catch (exception e2) {
            cout << e2.what() << endl;
        }

    } while (1);

    return 0;
}
