#pragma once
#include "gameObject.h"

class Cannon: public GameObject
{
public:
	float m_fDirectionX;
	float m_fDirectionY;
	sf::Sprite* m_sprite = new sf::Sprite();
	Cannon( float iX, float iY, int iHeight, int iWidth, float fDirectionX, float fDirectionY, Window* oWindow, GameManager* oGame, const char* cPath);

	float getDirectionX();
	float getDirectionY();

	void setDirection(float fX, float fY);
	void setOrientation(float vMousePositionX, float vMousePositionY, float fRatioX = 10, float fRatioY = 0);
};

