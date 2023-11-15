#include "ball.h"
#include "gameManager.h"

Ball::Ball(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame, float fDirectionX, float fDirectionY, float fSpeed) : GameObject(iX, iY, iRadius, oWindow, oGame) {
	m_fDirection.push_back(fDirectionX);
	m_fDirection.push_back(fDirectionY);
	m_fSpeed = fSpeed;
	(*oGame).m_voCircleCollide.push_back(this);

}

void Ball::move(float fDeltaTime) {
	/*std::cout << oGameObject->m_fDirectionX << std::endl;*/
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
void Ball::handleCollision(GameObject* oGameObject, float fDeltaTime, GameManager* oGame) {
	bool isCollide = isColliding(oGameObject);
	bool bIsAlreadyInCollision = false;
	char cSide = getSide(oGameObject);
	if (std::count(m_voObjectCollide.begin(), m_voObjectCollide.end(), oGameObject)) {
		bIsAlreadyInCollision = true;
	}
	if (isCollide) {
		if (bIsAlreadyInCollision == false)
		{
			onCollisionEnter(cSide, oGame, oGameObject);
		}
		else {
			onCollisionStay(cSide, oGameObject);
		}
	}
	else {
		if (bIsAlreadyInCollision) {
			onCollisionExit(cSide, oGameObject);
		}
	}
}

void Ball::onCollisionEnter(char cSide, GameManager* oGame, GameObject* oGameObject) {
	m_voObjectCollide.push_back(oGameObject);
	oGameObject->onCollisionEnter(cSide, oGame,oGameObject);
	/*on a besoin d appeler takeDamage*/
	bounce(cSide);
}