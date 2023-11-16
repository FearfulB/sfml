#include "canon.h"
#include "gameManager.h"
#include <iostream>

Cannon::Cannon(float iX, float iY, int iWidth, int iLength, float fDirectionX, float fDirectionY, Window* oWindow, GameManager* oGame, const char* cPath) : GameObject(iX, iY, iWidth, iLength, oWindow, oGame)
{
	m_fDirectionX = fDirectionX;
	m_fDirectionY = fDirectionY;

	m_sprite = new sf::Sprite();

	m_sprite = AssetManager::Get()->sprite(cPath, 1 ,1,iX, iY);
	
	
	(*oWindow).m_voSprite.push_back(m_sprite);
	



}
float Cannon::getDirectionX() {
	return m_fDirectionX;
}
float Cannon::getDirectionY() {
	return m_fDirectionY;
}

void Cannon::setOrientation(float vMousePositionX, float vMousePositionY, float fRatioX, float fRatioY) {
	m_Shape->setOrigin(fRatioX, fRatioY);
	int mouseAngle = -atan2(vMousePositionX - m_iX, vMousePositionY - m_iY) * 180 / 3.1459;
	m_Shape->setRotation(mouseAngle);
	m_sprite->setRotation(mouseAngle);
}


void Cannon::setDirection(float fX, float fY) {
	m_fDirectionX = fX / (float)sqrt(pow(fX, 2) + pow(fY, 2));
	m_fDirectionY = fY / (float)sqrt(pow(fX, 2) + pow(fY, 2));
}

Cannon::~Cannon() {

}
