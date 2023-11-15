#include "gameObject.h"
#include "windowManager.h"
#include "gameManager.h"
#include "canon.h"
#include "math.h"
#include "ball.h"
#include "brick.h"

#include <SFML/Graphics.hpp>
#include <iostream>


GameObject::GameObject(float iX, float iY, int iWidth, int iLength, Window* oWindow, GameManager* oGame) {
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWidth;
	m_iLength = iLength;
	m_Shape = new sf::RectangleShape(sf::Vector2f(m_iLength, m_iWidth));
	setPosition(m_iX, m_iY);
	(*oWindow).m_voGameWindowObjects.push_back(this);
	(*oGame).m_voRectCollide.push_back(this);
}
GameObject::GameObject(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame) {
	m_iX = iX;
	m_iY = iY;
	m_iRadius = iRadius;
	m_iLength = 2 * m_iRadius;
	m_iWidth = 2 * m_iRadius;

	m_Shape = new sf::CircleShape(m_iRadius);
	/*this->setPosition(m_iX, m_iY);*/
	(*oWindow).m_voGameWindowObjects.push_back(this);

}

sf::Shape& GameObject::getShape() {
	return *m_Shape;
}

float GameObject::getX() {
	return m_iX;
}

float GameObject::getY() {
	return m_iY;
}

int GameObject::getWidth() {
	return m_iWidth;
}

int GameObject::getLength() {
	return m_iLength;
}

int GameObject::getRadius() {
	return m_iRadius;
}


void GameObject::setPosition(float fX, float fY, float fRatioX, float fRatioY) {
	/*m_Shape->setOrigin(fRatioX, fRatioY);*/
	m_Shape->setPosition(fX, fY);
}



void GameObject::draw(Window& oWindow) {
	oWindow.m_oWindow->draw(getShape());
}

void GameObject::handleCollision(GameObject* oGameObject, float fDeltaTime, GameManager* oGame) {

}
void GameObject::onCollisionEnter(char cSide, GameManager* oGame, GameObject* oGameObject) {

}
void GameObject::onCollisionStay(char cSide, GameObject* oGameObject) {

}
void GameObject::onCollisionExit(char cSide, GameObject* oGameObject) {
	int iObjectIndex = 0;
	for (int i = 0; i < m_voObjectCollide.size(); i++) {
		if (m_voObjectCollide[i] == oGameObject) {
			iObjectIndex = i;
			break;
		}
	}
	m_voObjectCollide.erase(m_voObjectCollide.begin() + iObjectIndex);
}

bool GameObject::isColliding(GameObject* oGameObject) {
	bool bCollideX;
	bool bCollideY;
	if (getWidth() <= oGameObject->getWidth()) {
		bCollideY = math::isPointBetween(m_iY, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iWidth)
			|| math::isPointBetween(m_iY + m_iWidth, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iWidth);
	}
	else {
		bCollideY = math::isPointBetween(oGameObject->m_iY, m_iY, m_iY + m_iWidth)
			|| math::isPointBetween(oGameObject->m_iY + oGameObject->m_iWidth, m_iY, m_iY + m_iWidth);
	}
	if (m_iLength <= oGameObject->m_iLength) {
		bCollideX = math::isPointBetween(m_iX, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iLength)
			|| math::isPointBetween(m_iX + m_iLength, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iLength);
	}
	else {
		bCollideX = math::isPointBetween(oGameObject->m_iX, m_iX, m_iX + m_iLength)
			|| math::isPointBetween(oGameObject->m_iX + oGameObject->m_iLength, m_iX, m_iX + m_iLength);
	}
	return bCollideX && bCollideY;
}
char GameObject::getSide(GameObject* oGameObject)
{
	float overlapLR = std::min(m_iY , oGameObject->m_iY) - std::max(m_iY + m_iWidth,  oGameObject->m_iY + m_iWidth);
	float overlapUD = std::min(m_iX , oGameObject->m_iX) - std::max(m_iX + m_iLength, oGameObject->m_iX + m_iLength);
	

	if (overlapLR > overlapUD) {
		if (m_iX + m_iLength >= oGameObject->m_iX  and m_iX <= oGameObject->m_iX) {
			return 'l';
		}
		else {

			return 'r';
		}
	}
	else if (overlapLR < overlapUD) {

		if (m_iY + m_iWidth >= oGameObject->m_iY and m_iY <= oGameObject->m_iY) {
			return 'u';
		}
		else {
			return 'd';
		}
	}
}

GameObject::~GameObject()
{
	delete m_Shape;
}