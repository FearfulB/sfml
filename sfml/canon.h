#pragma once
#include "gameObject.h"

class Cannon: public GameObject
{
public:
	float m_fDirectionX;
	float m_fDirectionY;

	Cannon( float iX, float iY, int iWidth, int iLength, float fDirectionX, float fDirectionY, Window* oWindow, GameManager* oGame);

	float getDirectionX();
	float getDirectionY();

	void setDirection(float fX, float fY);
	void setOrientation(float vMousePositionX, float vMousePositionY, float fRatioX = 10, float fRatioY = 0);
};

