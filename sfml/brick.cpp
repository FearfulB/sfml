#include "brick.h"
#include "gameManager.h"


Brick::Brick(float iX, float iY, int iWidth, int iLength, Window* oWindow, GameManager* oGame) : GameObject(iX, iY, iWidth, iLength, oWindow, oGame) {
	(*oGame).m_voBrickCollide.push_back(this);
	m_Shape->setFillColor(sf::Color(88, 229, 7));
	life = 3;
}
void Brick::setColor() {
	life -= 1;
	if (life != 0) {

	}
}

Brick::~Brick() {

}
