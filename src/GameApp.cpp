#include "GameApp.h"


#define TABLE_WIDTH 5
#define TABLE_HEIGHT 5

namespace RobotGame {


GameApp::GameApp()
{
    this->table = make_unique<GameTable>(TABLE_WIDTH, TABLE_HEIGHT);
}

bool GameApp::hasRobotPlaced()
{
    return table && table->hasRobotPlaced();
}


void GameApp::processCommand(const Command &cmd)
{
    cmd.execute(*table);
}

}
