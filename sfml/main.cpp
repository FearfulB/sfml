#include "gameManager.h"
#include <iostream>

int main(int argc, char** argv)
{
    //init
    GameManager::Init();
    GameManager::Get()->mainLoop();  
    return 0;
}


