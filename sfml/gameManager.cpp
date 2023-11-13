#include "gameManager.h"


GameManager::GameManager()
{
    m_oWindow = new Window(640, 480, "Casse Brique");


    m_oRect = new GameObject(450, 200, 100, 100, m_oWindow, this);
    m_oCannon = new Cannon(310, 410, 50, 20, NULL, NULL, m_oWindow, this);
    m_oWallLeft = new GameObject(-10, 0, 480, 10, m_oWindow, this);
    m_oWallRight = new GameObject(640, 0, 480, 10, m_oWindow, this);
    m_oWallTop = new GameObject(0, -10, 10, 630, m_oWindow, this);

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


 void GameManager::mainLoop() 
 {
     sf::Clock oClock;

     

     bool move = false;
     float fDeltaTime = 0;
     while (m_oWindow->m_oWindow->isOpen())
     {

         sf::Vector2i localPosition = sf::Mouse::getPosition((*m_oWindow->m_oWindow));
         //EVENT
         sf::Event oEvent;

         m_oCannon->setOrientation(localPosition.x, localPosition.y);
         /*std::cout << m_oCannon->m_fDirectionX << std::endl;*/

         while (m_oWindow->m_oWindow->pollEvent(oEvent))
         {
             if (oEvent.type == sf::Event::Closed)
                 m_oWindow->m_oWindow->close();
             if (oEvent.type == sf::Event::MouseButtonPressed)
             {
                 if (oEvent.mouseButton.button == sf::Mouse::Left)
                 {
                     m_oCannon->setDirection((localPosition.x - m_oCannon->getX()), (localPosition.y- m_oCannon->getY()));
                     Ball* m_oCircle = new Ball(m_oCannon->getX(), m_oCannon->getY() - 50, 10, m_oWindow, this, m_oCannon->getDirectionX(),m_oCannon->getDirectionY());
                 }
             }
         }
        if (!m_voCircleCollide.empty()) {
            for (int i = 0; i < m_voRectCollide.size(); i++) { 
                for (int j = 0; j < m_voCircleCollide.size(); j++) {
                    m_voCircleCollide[j]->handleCollision(m_voRectCollide[i], fDeltaTime, m_voCircleCollide[j]);
                    m_voCircleCollide[j]->move(fDeltaTime);
                }
            }
        }

         //DRAW
         m_oWindow->m_oWindow->clear();
         m_oWindow->display();
         fDeltaTime = oClock.restart().asSeconds();
         
     }

     
 }
 



