#include "brick.h"
#include "gameManager.h"


Brick::Brick(float iX, float iY, int iWidth, int iLength, Window* oWindow, GameManager* oGame, int iLife) : GameObject(iX, iY, iWidth, iLength, oWindow, oGame) {
	
	m_iLife = iLife;
	color[0] = { sf::Color::Red };
	color[1] = { sf::Color::Yellow };
	color[2] = { sf::Color::Green };
	m_Shape->setFillColor(color[m_iLife-1]);
	(*oGame).m_voBrickCollide.push_back(this);

}
void Brick::takeDamage(GameManager* oGame,GameObject* oGameObject) {
	m_iLife -= 1;
	if (m_iLife != 0) {
		m_Shape->setFillColor(color[m_iLife-1]);
	}
	else {
		for (int i = 0; i < oGame->m_voRectCollide.size(); i++) {
			if (this == oGame->m_voRectCollide[i]) {
				oGame->m_voRectCollide.erase(oGame->m_voRectCollide.begin() + i);
			}
		}
		for (int i = 0; i < oGame->m_voBrickCollide.size(); i++) {
			if (this == oGame->m_voBrickCollide[i]) {
				oGame->m_voBrickCollide.erase(oGame->m_voBrickCollide.begin() + i);
			}
		}
		for (int i = 0; i < oGame->m_oWindow->m_voGameWindowObjects.size(); i++) {
			if (this == oGame->m_oWindow->m_voGameWindowObjects[i]) {
				oGame->m_oWindow->m_voGameWindowObjects.erase(oGame->m_oWindow->m_voGameWindowObjects.begin() + i);
			}
		}
	}
}
void Brick::onCollisionEnter(char cSide, GameManager* oGame, GameObject* oGameObject) {
	takeDamage(oGame,oGameObject);
}
Brick::~Brick() {

}
