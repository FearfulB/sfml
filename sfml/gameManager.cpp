#include "gameManager.h"

GameManager::GameManager()
{
    Window* oWindow;
}

GameManager* GameManager::pInstance = nullptr;


void GameManager::Init()
{
    GameManager::pInstance = new GameManager();
}

 GameManager* GameManager::Get()
 {
     return GameManager::pInstance;
 }



