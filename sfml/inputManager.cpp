#include "InputManager.h"
#include <SFML/Graphics.hpp>
InputManager::InputManager()
{

}

InputManager* InputManager::pInstance = nullptr;



void InputManager::Init()
{
    InputManager::pInstance = new InputManager();
}

InputManager* InputManager::Get()
{
    return InputManager::pInstance;
}
void InputManager::checkEvent()
{

    //InputManager::Get()->

    // sf::Event event;

    // // while there are pending events...
    // //while (window.pollEvent(event))
    // {
    //     // check the type of the event...
    //     switch (event.type)
    //     {
    //         // window closed
    //     case sf::Event::Closed:
    //         //window.close();
    //         break;

    //         // key pressed
    //     case sf::Event::KeyPressed:
            
    //             break;

    //         // we don't process other types of events
    //     default:
    //         break;
    //     }
    // }
}

void InputManager::keyPressed()
{

}