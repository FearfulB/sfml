#include "gameManager.h"

#include <fstream>;
#include <iostream>;
#include <string>;

GameManager::GameManager()
{
    AssetManager::Init();
    m_oWindowManager = new Window(640, 480, "Casse Brique F1");
    m_iNumberBall = 30;
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
            Brick* m_oBrick = new Brick(60 + (i % 8) * 60, 50 + (i / 8) * 40, 20, 50, m_oWindowManager, this, 1);
        }
        else if (m_viGrid[i] == 2) {
            Brick* m_oBrick = new Brick(60 + (i % 8) * 60, 50 + (i / 8) * 40, 20, 50, m_oWindowManager, this, 2);
        }
        else if (m_viGrid[i] == 3) {
            Brick* m_oBrick = new Brick(60 + (i % 8) * 60, 50 + (i / 8) * 40, 20, 50, m_oWindowManager, this, 3);
        }
    }
    fichier.close();
    
    m_oCannon = new Cannon(310, 410, 50, 20, NULL, NULL, m_oWindowManager, this, "img/canon.png");
    m_oWallLeft = new GameObject(-20, 0, 480, 20, m_oWindowManager, this);
    m_oWallRight = new GameObject(640, 0, 480, 20, m_oWindowManager, this);
    m_oWallTop = new GameObject(0, -20, 20, 630, m_oWindowManager, this);

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
     sf::Time t;
     bool bCanShoot = true;
     /*m_oWindowManager->m_oWindow->setFramerateLimit(120);*/
     float fDeltaTime = 0;
     while (m_oWindowManager->m_oWindow->isOpen())
     {
         float fCurrentTime = oClock.restart().asSeconds();
         float fps = 1.0f / (fCurrentTime);
 
         sf::Vector2i localPosition = sf::Mouse::getPosition((*m_oWindowManager->m_oWindow));
         //EVENT
         sf::Event oEvent;

         m_oCannon->setOrientation(localPosition.x, localPosition.y);

         while (m_oWindowManager->m_oWindow->pollEvent(oEvent))
         {
             if (oEvent.type == sf::Event::Closed)
                 m_oWindowManager->m_oWindow->close();
             if (oEvent.type == sf::Event::MouseButtonPressed)
             {
                 if (oEvent.mouseButton.button == sf::Mouse::Left && bCanShoot)
                 {
                     m_oCannon->setDirection((localPosition.x - m_oCannon->getX()), (localPosition.y- m_oCannon->getY()));
                     Ball* m_oCircle = new Ball(m_oCannon->getX(), m_oCannon->getY(), 5, m_oWindowManager, this, m_oCannon->getDirectionX(),m_oCannon->getDirectionY(),300.f);
                     m_iNumberBall -= 1;
                     bCanShoot = false;
                 }
             }
         }
         
         if (!m_voCircleCollide.empty()) {
             for (int i = 0; i < 10; i++) {
                 m_voCircleCollide[0]->move(fDeltaTime/10);
                 for (int i = 0; i < m_voRectCollide.size(); i++) {
                     if (m_voRectCollide[i] != m_oCannon) {
                         m_voCircleCollide[0]->handleCollision(m_voRectCollide[i], fDeltaTime, this);
                     }
                 }
             }

             if (m_voCircleCollide[0]->getY() > m_oWindowManager->getHeight() || m_voCircleCollide[0]->getX() > m_oWindowManager->getWidth() || m_voCircleCollide[0]->getX() < 0) {
                 for (int i = 0; i < m_oWindowManager->m_voGameWindowObjects.size(); i++) {
                     if (m_voCircleCollide[0] == m_oWindowManager->m_voGameWindowObjects[i]) {
                         m_oWindowManager->m_voGameWindowObjects.erase(m_oWindowManager->m_voGameWindowObjects.begin() + i);
                         bCanShoot = true;
                     }
                 }
                 m_voCircleCollide.pop_back();
             }
         }


         fDeltaTime = oClock.restart().asSeconds();

         //DRAW
         m_oWindowManager->m_oWindow->clear();
        
         m_oWindowManager->display(m_iNumberBall);

         

         if ((checkWin() == true) || (checkLose() == true && m_voCircleCollide.empty()))
         {
             m_oWindowManager->m_oWindow->clear();
             (checkWin())? m_oWindowManager->displayWin() : m_oWindowManager->displayLose();
             
             while (m_oWindowManager->m_oWindow->isOpen()) {
                 while (m_oWindowManager->m_oWindow->pollEvent(oEvent))
                 {
                     if (oEvent.type == sf::Event::Closed) {
                         m_oWindowManager->m_oWindow->close();
                     }
                 }
             }
         }
         
     }

     
 }
 



