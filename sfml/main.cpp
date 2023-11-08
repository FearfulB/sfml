#include "gameObject.h"
#include "math.h"

#include <SFML/Graphics.hpp>
#include <iostream>


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Frozen Bubble");
    sf::Clock oClock;

    GameObject* oCircle = new GameObject(310, 390, 10);
    GameObject* rect = new GameObject(450, 200, 100, 100);
    GameObject* oCanon = new GameObject(310, 410, 50, 20);
    GameObject* oWallLeft = new GameObject(0, 0, 480, 10);
    float fDirectionX = 1 * sqrt(2);
    float fDirectionY = -1 * sqrt(2);
    float fDeltaTime = 0.0f;
    //GameLoop
    while (oWindow.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(oWindow);;
        //EVENT
        sf::Event oEvent;

       
        
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
 /*       if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {*/
        oCanon->move(fDeltaTime, fDirectionX, fDirectionY);
        //UPDATE
        if (oCanon->isColliding(rect) ) {
            std::cout << "aa" << std::endl;
            fDirectionX = oCircle->bounce(fDeltaTime, fDirectionX, fDirectionY);
        };
       
         /*oCanon->rotate(localPosition.x, localPosition.y);*/
        //DRAW

        oWindow.clear();
        oWindow.draw(oCircle->getShape());
        oWindow.draw(rect->getShape());
        oWindow.draw(oWallLeft->getShape());
        oWindow.draw(oCanon->getShape());

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}


