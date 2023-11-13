#include "gameObject.h"
#include "math.h"
#include "windowManager.h"
#include "gameManager.h"

#include <SFML/Graphics.hpp>
#include <iostream>


int main(int argc, char** argv)
{
    //

    //init
    GameManager::Init();

    GameManager::Get()->mainLoop();
    
    return 0;
}


