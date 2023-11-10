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
    Window* pWindow = new Window(640, 480, "Casse Brique");

    sf::Clock oClock;

    float fDirectionX = -1 / sqrt(2);
    float fDirectionY = -1 / sqrt(2);



    GameObject* oCircle = new GameObject(30, 300, 10, fDirectionX, fDirectionY,pWindow);
    GameObject* rect = new GameObject(450, 200, 100, 100, pWindow);
    GameObject* oCanon = new GameObject(310, 410, 50, 20, pWindow);
    GameObject* oWallLeft = new GameObject(-10, 0, 480, 10, pWindow);
    GameObject* oWallRight = new GameObject(640, 0, 480, 10, pWindow);
    GameObject* oWallTop = new GameObject(0, -10, 10, 630, pWindow);

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
        oCircle->move(fDeltaTime, oCircle);
        for (int i = 0; i < pWindow->m_voRectCollide.size(); i++) {
            oCircle->handleCollision(pWindow->m_voRectCollide[i], fDeltaTime);
        }
        /*oCircle->removeObject(pWindow);*/
        oCanon->rotate(localPosition.x, localPosition.y);

        //DRAW
        pWindow->m_oWindow->clear();
        pWindow->display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}


