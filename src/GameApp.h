#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <string>
#include "GameTable.h"
#include "Command.h"

using namespace std;

namespace robotgame {


class GameApp
{
public:
    GameApp();

    bool hasRobotPlaced();

    void processCommand(const Command& cmd);
    const GameTablePtr& getGameTable() const {
        return m_table;
    }

private:
    GameTablePtr m_table;
};

}

#endif // GAMEAPP_H
