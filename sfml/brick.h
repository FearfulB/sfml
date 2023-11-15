#pragma once
#include "gameObject.h"

class Brick : public GameObject
{
public:
	int m_iLife;
	sf::Color color[3];

	Brick(float iX, float iY, int iWidth, int iLength, Window* oWindow, GameManager* oGame, int iLife);

	void takeDamage(GameManager* oGame, GameObject* oGameObject);
	void onCollisionEnter(char cSide, GameManager* oGame, GameObject* oGameObject) override;
	~Brick();
};
