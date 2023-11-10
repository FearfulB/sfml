#include "gameObject.h"
#include "math.h"
#include "windowManager.h"

#include <SFML/Graphics.hpp>
#include <iostream>


int main(int argc, char** argv)
{
    //

    //init

    //Cr�ation d'une fen�tre
	sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Frozen Bubble");
    
    sf::Clock oClock;
    float fDirectionX = -1 / sqrt(2);
    float fDirectionY = -1 / sqrt(2);
    /*std::cout << fDirectionX;*/
    GameObject* oCircle = new GameObject(340, 60, 10);
    GameObject* rect = new GameObject(450, 200, 100, 100, fDirectionX, fDirectionY);
    GameObject* oCanon = new GameObject(310, 410, 50, 20, fDirectionX, fDirectionY);
    GameObject* oWallLeft = new GameObject(0, 0, 480, 10, fDirectionX, fDirectionY);
    GameObject* oWallRight = new GameObject(630, 0, 480, 10, fDirectionX, fDirectionY);
    GameObject* oWallTop = new GameObject(0, 0, 10, 630, fDirectionX, fDirectionY);

    float fDeltaTime = 0;
    //GameLoop
    while (oWindow.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(oWindow);
        //EVENT
        sf::Event oEvent;

        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        oCircle->move(fDeltaTime, oCanon);
        oCircle->handleCollision(oWallTop, fDeltaTime);
        //UPDATE
        //if (oCircle->isColliding(oWallTop)) {
        //    site = oCircle->checkSide(oWallTop);
        //    if (site == 'l' || site == 'r') {
        //        fDirectionX = oCircle->onCollisionEnter(fDeltaTime, fDirectionX, fDirectionY, site);
        //    }
        //    else {
        //        fDirectionY = oCircle->onCollisionEnter(fDeltaTime, fDirectionX, fDirectionY, site);
        //    }

        //};
       
         oCanon->rotate(localPosition.x, localPosition.y);
        //DRAW

        oWindow.clear();
        oWindow.draw(oCircle->getShape());
        oWindow.draw(rect->getShape());
        oWindow.draw(oWallLeft->getShape());
        oWindow.draw(oWallRight->getShape());
        oWindow.draw(oWallTop->getShape());
        oWindow.draw(oCanon->getShape());

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}


