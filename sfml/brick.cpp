#include "brick.h"
#include "gameManager.h"


Brick::Brick(float iX, float iY, int iWidth, int iLength, Window* oWindow, GameManager* oGame, int iLife) : GameObject(iX, iY, iWidth, iLength, oWindow, oGame) {
	(*oGame).m_voBrickCollide.push_back(this);

	m_iLife = iLife;
	color[0] = { sf::Color::Red };
	color[1] = { sf::Color::Yellow };
	color[2] = { sf::Color::Green };
	m_Shape->setFillColor(color[m_iLife-1]);


}
void Brick::setColor(GameManager* oGame) {
	m_iLife -= 1;
	if (m_iLife != 0) {
		m_Shape->setFillColor(color[m_iLife -1]);
	}
	else {
		int indexRect = 0;
		for (int i = 0; i < oGame->m_voBrickCollide.size(); i++) {
			if ((*oGame).m_voBrickCollide[i]->m_iLife == 0) {
				oGame->m_voBrickCollide.erase(oGame->m_voBrickCollide.begin() + i );
			}
		}
	}
	
}

Brick::~Brick() {

}
