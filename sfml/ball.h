#pragma once
#include "gameObject.h"


#include <vector>
class Ball : public GameObject
{
public:
	std::vector<float> m_fDirection;

	Ball(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame, float fDirectionX, float fDirectionY);
	void move(float fDeltaTime);
	void bounce(char cSite);
};

