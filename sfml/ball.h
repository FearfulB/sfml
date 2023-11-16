#pragma once
#include "gameObject.h"


#include <vector>
class Ball : public GameObject
{
public:
	std::vector<float> m_fDirection;
	float m_fSpeed;

	Ball(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame, float fDirectionX, float fDirectionY, float fSpeed);
	void move(float fDeltaTime);
	void bounce(char cSite);
	void handleCollision(GameObject* oGameObject, float fDeltaTime, GameManager* oGame) override;
	void onCollisionEnter(char cSide, GameManager* oGame, GameObject* oGameObject) override;
	void onCollisionExit(GameObject* oGameObject) override;
};
