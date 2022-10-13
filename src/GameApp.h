#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <string>
#include "GameTable.h"
#include "Command.h"

using namespace std;

namespace RobotGame {

    class GameApp {
    public:
        GameApp();

        bool hasRobotPlaced();

        void processCommand(const Command &cmd);

        const GameTablePtr &getGameTable() const {
            return table;
        }

    private:
        GameTablePtr table;
    };

}

#endif // GAMEAPP_H
