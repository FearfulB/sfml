#include "gameObject.h"

#include <SFML/Graphics.hpp>
#include <iostream>


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Frozen Bubble");
    sf::Clock oClock;

    GameObject* oRect = new GameObject(20, 200, 150, 200);
    GameObject* oCircle = new GameObject(310, 390, 10);
    GameObject* oCanon = new GameObject(310, 410, 50, 20);

    float fDeltaTime = oClock.restart().asSeconds();
    //GameLoop
    while (oWindow.isOpen())
    {
        sf::Vector2i globalPosition = sf::Mouse::getPosition();
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
        //UPDATE
         oCircle->ballMovement(fDeltaTime);
        //DRAW
        oCanon->canonRotation(globalPosition.x);
        oWindow.clear();
        oWindow.draw(oRect->getShape());
        oWindow.draw(oCircle->getShape());
        oWindow.draw(oCanon->getShape());

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}


