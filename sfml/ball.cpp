#include "ball.h"
#include "gameManager.h"

Ball::Ball(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame, float fDirectionX, float fDirectionY) : GameObject(iX, iY, iRadius, oWindow, oGame) {
	m_fDirection.push_back(fDirectionX);
	m_fDirection.push_back(fDirectionY);
	(*oGame).m_voCircleCollide.push_back(this);

}

void Ball::move(float fDeltaTime) {
	/*std::cout << oGameObject->m_fDirectionX << std::endl;*/
	m_iX += m_fDirection[0] * fDeltaTime * 10.f;
	m_iY += m_fDirection[1] * fDeltaTime * 10.f;
	setPosition(m_iX, m_iY);
}

void Ball::bounce(char cSite) {

	/*a changer si l on veux faire le bonus avec les balles qui collisionne*/
	if (cSite == 'l' || cSite == 'r') {
		std::cout << "ll";
		m_fDirection[0] = -m_fDirection[0];
	}
	else if(cSite == 'u' || cSite == 'd') {
		std::cout << "tt";
		m_fDirection[1] = -m_fDirection[1];
	}
	else
	{
		std::cout << "zz";
		m_fDirection[0] = -m_fDirection[0];
		m_fDirection[1] = -m_fDirection[1];
	}

}