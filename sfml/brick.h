#pragma once
#include "gameObject.h"

class Brick : public GameObject
{
public:
	int life;

	Brick(float iX, float iY, int iWidth, int iLength, Window* oWindow, GameManager* oGame);

	void setColor();
	~Brick();
};
