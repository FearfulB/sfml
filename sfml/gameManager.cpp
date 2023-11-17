#include "gameManager.h"

#include <fstream>;
#include <iostream>;
#include <string>;

GameManager::GameManager()
{
    AssetManager::Init();
    m_oWindow = new Window(640, 480, "Casse Brique F1");
    m_iNumberBall = 20;
    std::string sFileName("grid.txt");
    std::ifstream fichier(sFileName);

    if (!fichier.is_open()) {
        std::cerr << "Could not open the file - '" << sFileName << "'" << std::endl;
    }
    std::string line;

    while (getline(fichier, line)) {
        for (int i = 0; i < line.length(); i++) {
            const char cLetter = line[i];
            /* le if est a changer */
            if (cLetter == '0' || cLetter == '1' || cLetter == '2' || cLetter == '3') {
                int j = atoi(&cLetter);
                m_viGrid.push_back(j);
            }

        }
    }
    for (int i = 0; i < m_viGrid.size(); i++) {
        if (m_viGrid[i] == 1) {
            Brick* m_oBrick = new Brick(60 + (i % 8) * 60, 50 + (i / 8) * 40, 20, 50, m_oWindow, this, 1);
        }
        else if (m_viGrid[i] == 2) {
            Brick* m_oBrick = new Brick(60 + (i % 8) * 60, 50 + (i / 8) * 40, 20, 50, m_oWindow, this, 2);
        }
        else if (m_viGrid[i] == 3) {
            Brick* m_oBrick = new Brick(60 + (i % 8) * 60, 50 + (i / 8) * 40, 20, 50, m_oWindow, this, 3);
        }
    }
    fichier.close();
    

    m_oCannon = new Cannon(310, 410, 50, 20, NULL, NULL, m_oWindow, this, "img/canon.png");
    m_oWallLeft = new GameObject(-20, 0, 480, 20, m_oWindow, this);
    m_oWallRight = new GameObject(640, 0, 480, 20, m_oWindow, this);
    m_oWallTop = new GameObject(0, -20, 20, 630, m_oWindow, this);

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

 bool GameManager::checkWin() {
     if (m_voBrickCollide.empty()) {
         return true;
     }
 }
 bool GameManager::checkLose() {
     if (m_iNumberBall <= 0) {
         return true;
     }
 }

 void GameManager::mainLoop() 
 {
     sf::Clock oClock;

     bool bCanShoot = true;

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
                 if (oEvent.mouseButton.button == sf::Mouse::Left && bCanShoot)
                 {
                     m_oCannon->setDirection((localPosition.x - m_oCannon->getX()), (localPosition.y- m_oCannon->getY()));
                     Ball* m_oCircle = new Ball(m_oCannon->getX(), m_oCannon->getY(), 5, m_oWindow, this, m_oCannon->getDirectionX(),m_oCannon->getDirectionY(),300.f);
                     
                     m_iNumberBall -= 1;
                     bCanShoot = false;
                 }
             }
         }
         
         if (!m_voCircleCollide.empty()) {
             m_voCircleCollide[0]->move(fDeltaTime);
             for (int i = 0; i < m_voRectCollide.size(); i++) {
                if (m_voRectCollide[i] != m_oCannon) {
                    m_voCircleCollide[0]->handleCollision(m_voRectCollide[i], fDeltaTime, this);
                }
             }
             if (m_voCircleCollide[0]->getY() > m_oWindow->getHeight() || m_voCircleCollide[0]->getX() > m_oWindow->getWidth() || m_voCircleCollide[0]->getX() < 0) {
                 for (int i = 0; i < m_oWindow->m_voGameWindowObjects.size(); i++) {
                     if (m_voCircleCollide[0] == m_oWindow->m_voGameWindowObjects[i]) {
                         m_oWindow->m_voGameWindowObjects.erase(m_oWindow->m_voGameWindowObjects.begin() + i);
                         bCanShoot = true;
                     }
                 }
                 m_voCircleCollide.pop_back();
             }
         }



         //DRAW
         m_oWindow->m_oWindow->clear();
        
         m_oWindow->display(m_iNumberBall);
         
         fDeltaTime = oClock.restart().asSeconds();
         if ((checkWin() == true) || (checkLose() == true && m_voCircleCollide.empty()))
         {
             m_oWindow->m_oWindow->clear();
             (checkWin())? m_oWindow->displayWin() : m_oWindow->displayLose();
             
             while (m_oWindow->m_oWindow->isOpen()) {
                 while (m_oWindow->m_oWindow->pollEvent(oEvent))
                 {
                     if (oEvent.type == sf::Event::Closed) {
                         m_oWindow->m_oWindow->close();
                     }
                 }
             }
         }
         
     }

     
 }
 



