#include "gameManager.h"


GameManager::GameManager()
{
    m_oWindow = new Window(640, 480, "Casse Brique");
    float fDirectionX = -1 / sqrt(2);
    float fDirectionY = -1 / sqrt(2);

    m_oRect = new GameObject(450, 200, 100, 100, fDirectionX, fDirectionY, m_oWindow, this);
    m_oCanon = new GameObject(310, 410, 50, 20, fDirectionX, fDirectionY, m_oWindow, this);
    m_oCircle = new GameObject(m_oCanon->m_iX, m_oCanon->m_iY, 10, fDirectionX, fDirectionY, m_oWindow, this);
    m_oWallLeft = new GameObject(-10, 0, 480, 10, fDirectionX, fDirectionY, m_oWindow, this);
    m_oWallRight = new GameObject(640, 0, 480, 10, fDirectionX, fDirectionY, m_oWindow, this);
    m_oWallTop = new GameObject(0, -10, 10, 630, fDirectionX, fDirectionY, m_oWindow, this);

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

         while (m_oWindow->m_oWindow->pollEvent(oEvent))
         {
             if (oEvent.type == sf::Event::Closed)
                 m_oWindow->m_oWindow->close();
         }
         //if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
         //{
         //    move = true;
         //    GameObject* oCircle = new GameObject(oCanon->m_iX, oCanon->m_iY, 10, fDirectionX, fDirectionY, pWindow);
         //}
         /*if (move) {*/
         m_oCircle->move(fDeltaTime, m_oCircle);
         for (int i = 0; i < m_voRectCollide.size(); i++) {
             m_oCircle->handleCollision(m_voRectCollide[i], fDeltaTime);
         }
         //}
         /*oCircle->removeObject(pWindow);*/
         m_oCanon->setRotation(localPosition.x, localPosition.y);

         //DRAW
         m_oWindow->m_oWindow->clear();
         m_oWindow->display();

         fDeltaTime = oClock.restart().asSeconds();
     }

     
 }
 



