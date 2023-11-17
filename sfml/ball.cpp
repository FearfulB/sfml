#include "ball.h"
#include "gameManager.h"

#include <iostream>

Ball::Ball(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame, float fDirectionX, float fDirectionY, float fSpeed) : GameObject(iX, iY, iRadius, oWindow, oGame) {
	m_fDirection.push_back(fDirectionX);
	m_fDirection.push_back(fDirectionY);
	m_fSpeed = fSpeed;
	(*oGame).m_voCircleCollide.push_back(this);
	m_Shape->setOrigin(0.5f, 0.5f);

}

void Ball::move(float fDeltaTime) {
	m_iX += m_fDirection[0] * fDeltaTime * m_fSpeed;
	m_iY += m_fDirection[1] * fDeltaTime * m_fSpeed;
	setPosition(m_iX, m_iY);
}

void Ball::bounce(char cSite) {

	/*a changer si l on veux faire le bonus avec les balles qui collisionne*/
	if (cSite == 'l' || cSite == 'r') {
		m_fDirection[0] = -m_fDirection[0];
	}
	else if (cSite == 'u' || cSite == 'd') {
		m_fDirection[1] = -m_fDirection[1];
	}
	else
	{
		m_fDirection[0] = -m_fDirection[0];
		m_fDirection[1] = -m_fDirection[1];
	}
}

void Ball::onCollisionEnter(char cSide, GameManager* oGame, GameObject* oGameObject) {
	bounce(cSide);
}

void Ball::onCollisionExit(GameObject* oGameObject) {

}