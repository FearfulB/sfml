#include "gameObject.h"
#include "math.h"
#include "windowManager.h"

#include <SFML/Graphics.hpp>
#include <iostream>


int main(int argc, char** argv)
{
    //

    //init

    //Création d'une fenêtre
	/*sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Frozen Bubble");*/
    Window* pWindow = new Window(640, 480, "Casse Brique");

    sf::Clock oClock;
    float fDirectionX = -1 / sqrt(2);
    float fDirectionY = -1 / sqrt(2);
    /*std::cout << fDirectionX;*/
    GameObject* oCircle = new GameObject(30, 100, 10);
    GameObject* rect = new GameObject(450, 200, 100, 100, fDirectionX, fDirectionY);
    GameObject* oCanon = new GameObject(310, 410, 50, 20, fDirectionX, fDirectionY);
    GameObject* oWallLeft = new GameObject(-10, 0, 480, 10, fDirectionX, fDirectionY);
    GameObject* oWallRight = new GameObject(640, 0, 480, 10, fDirectionX, fDirectionY);
    GameObject* oWallTop = new GameObject(0, -10, 10, 630, fDirectionX, fDirectionY);

    float fDeltaTime = 0;
    //GameLoop
    while (pWindow->m_oWindow->isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition((*pWindow->m_oWindow));
        //EVENT
        sf::Event oEvent;

        while (pWindow->m_oWindow->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                pWindow->m_oWindow->close();
        }
        oCircle->move(fDeltaTime, oWallLeft);
        oCircle->handleCollision(oWallLeft, fDeltaTime);
       
            oCanon->rotate(localPosition.x, localPosition.y);
        //DRAW

        pWindow->m_oWindow->clear();
        pWindow->m_oWindow->draw(oCircle->getShape());
        pWindow->m_oWindow->draw(rect->getShape());
        pWindow->m_oWindow->draw(oWallLeft->getShape());
        pWindow->m_oWindow->draw(oWallRight->getShape());
        pWindow->m_oWindow->draw(oWallTop->getShape());
        pWindow->m_oWindow->draw(oCanon->getShape());
        pWindow->m_oWindow->display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}


