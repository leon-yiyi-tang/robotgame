#include "GameApp.h"



#define TABLE_WIDTH 5
#define TABLE_HEIGHT 5

GameApp::GameApp()
{
    this->m_table = GameTablePtr(new GameTable(TABLE_WIDTH, TABLE_HEIGHT));
}

bool GameApp::hasRobotPlaced()
{
    return m_table && m_table->hasRobotPlaced();
}


void GameApp::processCommand(const Command &cmd)
{
    //if (cmd.isPlaceCommand() || hasRobotPlaced()){
        cmd.visit(*m_table);
    //}
}
