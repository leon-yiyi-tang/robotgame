#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <string>
#include "GameTable.h"
#include "Command.h"

using namespace std;

class GameApp
{
public:
    GameApp();

    bool hasRobotPlaced();

    void processCommand(const Command& cmd);

private:
    GameTablePtr m_table;
};

#endif // GAMEAPP_H
