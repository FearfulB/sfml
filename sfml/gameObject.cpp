#include "gameObject.h"
#include "math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject(float iX, float iY, int iWidth, int iLength)
{
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWidth;
	m_iLength = iLength;
	m_bIsCollide = false;
	m_Shape = new sf::RectangleShape(sf::Vector2f(m_iLength, m_iWidth));
	m_Shape->setPosition(m_iX, m_iY);
}
GameObject::GameObject(float iX, float iY, int iRadius) {
	m_iX = iX;
	m_iY = iY;
	m_iRadius = iRadius;
	m_iLength = 2 * m_iRadius;
	m_iWidth = 2 * m_iRadius;
	m_bIsCollide = false;
	m_Shape = new sf::CircleShape(m_iRadius);
	m_Shape->setPosition(m_iX, m_iY);
}
sf::Shape& GameObject::getShape() {
	return *m_Shape;
}

void GameObject::move(float fDeltaTime, float fDirectionX, float fDirectionY) {
	m_iX += fDirectionX * fDeltaTime * 60.f;
	m_iY += fDirectionY * fDeltaTime * 60.f;
	m_Shape->setPosition(m_iX, m_iY);
}

void GameObject::rotate(float vMousePositionX, float vMousePositionY) {
	
	int mouseAngle = -atan2(vMousePositionX - m_iX, vMousePositionY - m_iY) * 180 / 3.1459;

	m_Shape->setRotation(mouseAngle);

}

void GameObject::handleCollision(GameObject* oGameObject) {
	bool isCollide = isColliding(oGameObject);
	if (isCollide) {
		//if (oCircle->isColliding(oWallTop)) {
        //    site = oCircle->checkSide(oWallTop);
        //    if (site == 'l' || site == 'r') {
        //        fDirectionX = oCircle->onCollisionEnter(fDeltaTime, fDirectionX, fDirectionY, site);
        //    }
        //    else {
        //        fDirectionY = oCircle->onCollisionEnter(fDeltaTime, fDirectionX, fDirectionY, site);
        //    }

        //};
		if (std::find(m_vObjectCollide.begin(), m_vObjectCollide.end(), oGameObject) != m_vObjectCollide.end()) {
			onCollisionStay();
		}
		else {
			m_vObjectCollide.push_back(oGameObject);
			onCollisionEnter();
		}
	}

	else {
		onCollisionExit();
	}
}
float GameObject::onCollisionEnter(float  fDeltaTime, float fDirectionX, float fDirectionY, char cSite) {
	m_bIsCollide = true;
	return bounce(fDeltaTime, fDirectionX, fDirectionY, cSite);
}
void GameObject::onCollisionStay() {
	
}
void GameObject::onCollisionExit() {
	m_bIsCollide = false;
	m_vObjectCollide.pop_back();
}

bool GameObject::isColliding(GameObject* oGameObject) {
	int iCollidValue = 0;
	if (m_iWidth < oGameObject->m_iWidth) {
		(math::isPointBetween(m_iY, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iWidth)
			|| math::isPointBetween(m_iY + m_iWidth, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iWidth)) ? iCollidValue += 1 : false;
	}
	else {
		(math::isPointBetween(oGameObject->m_iY, m_iY, m_iY + m_iWidth)
			|| math::isPointBetween(oGameObject->m_iY + oGameObject->m_iWidth, m_iY, m_iY + m_iWidth)) ? iCollidValue += 1 : false;
	}
	if (m_iLength < oGameObject->m_iLength) {
		(math::isPointBetween(m_iX, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iLength)
			|| math::isPointBetween(m_iX + m_iLength, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iLength)) ? iCollidValue += 1 : false;
	}
	else {
		(math::isPointBetween(oGameObject->m_iX, m_iX, m_iX + m_iLength)
			|| math::isPointBetween(oGameObject->m_iX + oGameObject->m_iLength, m_iX, m_iX + m_iLength)) ? iCollidValue += 1 : false;
	}
	if (iCollidValue == 2) {
		m_vObjectCollide.push_back(oGameObject);
		iCollidValue = 0;
		return true;
	}
	else {
		iCollidValue = 0;
		return false;
	}
}
char GameObject::checkSide(GameObject* oGameObject)
{
	float overlabLR = std::min(m_iY + m_iLength, oGameObject->m_iY+ m_iLength) - std::max(m_iY + m_iLength, oGameObject->m_iY + oGameObject->m_iLength);
	float overlabUD = std::min(m_iX + m_iWidth, oGameObject->m_iX+ m_iWidth) - std::max(m_iX + m_iWidth, oGameObject->m_iX + oGameObject->m_iWidth);

	if (overlabLR > overlabUD) {
		if (m_iX <= oGameObject->m_iX + oGameObject->m_iWidth and m_iX >= oGameObject->m_iX) {
			std::cout << "right";
			return 'r';
		}
		else {
			std::cout << "left";
			return 'l';
		}
	}
	else if (overlabLR < overlabUD) {
		
		if (m_iY + m_iLength >= oGameObject->m_iY and m_iY <= oGameObject->m_iY) {
			std::cout << "up";
			return 'u';
		}
		else {
			std::cout << "down";
			return 'd';
		}
	}
}
float GameObject::bounce(float  fDeltaTime, float fDirectionX, float fDirectionY, char cSite) {
	/*a changer si l on veux faire le bonus avec les balles qui collisionne*/
	if(cSite == 'l' || cSite =='r') {
		return fDirectionX = -fDirectionX;
	}
	else{
		return fDirectionY = -fDirectionY;
	} 
		
}

GameObject::~GameObject()
{
	delete m_Shape;
}