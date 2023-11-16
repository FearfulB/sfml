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
void GameObject::onCollisionExit(GameObject* oGameObject) {

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
	int iGo1Xmin = oGameObject->getX();
	int iGo1Xmax = oGameObject->getX() + oGameObject->getLength();
	int iGo1Ymin = oGameObject->getY();
	int iGo1Ymax = oGameObject->getY() + oGameObject->getWidth();
	int iXmin = getX();
	int iXmax = getX() + getLength();
	int iYmin = getY();
	int iYmax = getY() + getWidth();

	if ((iYmin - iGo1Ymin > iYmin - iGo1Ymax) && (iXmax - iGo1Xmin > iGo1Ymax - iYmin ) && (math::isPointBetween(iXmin,iGo1Xmin,iGo1Xmax))&& (math::isPointBetween(iYmin,iGo1Ymin,iGo1Ymax))) {
		return 'd';
	}
	else if ((iYmax - iGo1Ymin > iYmax - iGo1Ymax) && (iGo1Xmax - iXmin > iGo1Ymax - iYmin ) &&  (math::isPointBetween(iXmax, iGo1Xmin, iGo1Xmax)) && (math::isPointBetween(iYmax, iGo1Ymin, iGo1Ymax))) {
		return 'u';
	}
	else if ((iGo1Xmax - iXmin > iXmin - iGo1Xmin ) && (iGo1Ymax - iYmin > iGo1Xmax - iXmin) && (math::isPointBetween(iXmin, iGo1Xmin, iGo1Xmax)) && (math::isPointBetween(iYmin, iGo1Ymin, iGo1Ymax))) {
		return 'r';
	}
	else if ((iXmax - iGo1Xmin > iGo1Xmin - iXmin) && (iGo1Ymax - iYmax > iXmax - iGo1Xmin) && (math::isPointBetween(iXmax, iGo1Xmin, iGo1Xmax)) && (math::isPointBetween(iYmax, iGo1Ymin, iGo1Ymax))) {
		return 'l';
	}
}

GameObject::~GameObject()
{
	delete m_Shape;
}