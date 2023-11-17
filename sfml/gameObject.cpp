#include "gameObject.h"
#include "windowManager.h"
#include "gameManager.h"
#include "canon.h"
#include "math.h"
#include "ball.h"
#include "brick.h"

#include <SFML/Graphics.hpp>
#include <iostream>


GameObject::GameObject(float iX, float iY, int iHeight, int iWidth, Window* oWindow, GameManager* oGame) {
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_Shape = new sf::RectangleShape(sf::Vector2f(m_iWidth, m_iHeight));
	setPosition(m_iX, m_iY);
	(*oWindow).m_voGameWindowObjects.push_back(this);
	(*oGame).m_voRectCollide.push_back(this);
}
GameObject::GameObject(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame) {
	m_iX = iX;
	m_iY = iY;
	m_iRadius = iRadius;
	m_iHeight = 2 * m_iRadius;
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

int GameObject::getHeight() {
	return m_iHeight;
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
	bool isCollide = isColliding(oGameObject);

	auto bIsAlreadyInCollision = std::find(m_voObjectCollide.begin(), m_voObjectCollide.end(), oGameObject);


	if (isCollide) {

		char cSide = getSide(oGameObject);
		if (bIsAlreadyInCollision == m_voObjectCollide.end())
		{
			m_voObjectCollide.push_back(oGameObject);

			onCollisionEnter(cSide, oGame, oGameObject);
			oGameObject->onCollisionEnter(cSide, oGame, oGameObject);
		}
		else {

			onCollisionStay(cSide, oGameObject);
		}
	}
	else {
		if (bIsAlreadyInCollision != m_voObjectCollide.end()) {

			onCollisionExit(oGameObject);
			m_voObjectCollide.erase(bIsAlreadyInCollision);
		}
	}
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
		bCollideY = math::isPointBetween(getY(), oGameObject->getY(), oGameObject->getY() + oGameObject->getHeight())
			|| math::isPointBetween(getY() + getHeight(), oGameObject->getY(), oGameObject->getY() + oGameObject->getHeight());
	}
	else {
		bCollideY = math::isPointBetween(oGameObject->getY(), getY(), getY() + getHeight())
			|| math::isPointBetween(oGameObject->getY() + oGameObject->getHeight(), getY(), getY() + getHeight());
	}
	if (getWidth() <= oGameObject->getWidth()) {
		bCollideX = math::isPointBetween(getX(), oGameObject->getX(), oGameObject->getX() + oGameObject->getWidth())
			|| math::isPointBetween(getX() + getWidth(), oGameObject->getX(), oGameObject->getX() + oGameObject->getWidth());
	}
	else {
		bCollideX = math::isPointBetween(oGameObject->getX(), getX(), getX() + getWidth())
			|| math::isPointBetween(oGameObject->getX() + oGameObject->getWidth(), getX(), getX() + getWidth());
	}
	return bCollideX && bCollideY;
}
char GameObject::getSide(GameObject* oGameObject)
{
	int iGo1Xmin = oGameObject->getX();
	int iGo1Xmax = oGameObject->getX() + oGameObject->getWidth();
	int iGo1Ymin = oGameObject->getY();
	int iGo1Ymax = oGameObject->getY() + oGameObject->getHeight();
	int iXmin = getX();
	int iXmax = getX() + getWidth();
	int iYmin = getY();
	int iYmax = getY() + getHeight();

	if ((iYmin - iGo1Ymin > iYmin - iGo1Ymax) && (iXmax - iGo1Xmin > iGo1Ymax - iYmin ) && (math::isPointBetween(iXmin,iGo1Xmin,iGo1Xmax))&& (math::isPointBetween(iYmin,iGo1Ymin,iGo1Ymax))) {
		return 'd';
	}
	else if ((iYmax - iGo1Ymin > iYmax - iGo1Ymax) && (iGo1Xmax - iXmin > iGo1Ymax - iYmin ) &&  (math::isPointBetween(iXmax, iGo1Xmin, iGo1Xmax)) && (math::isPointBetween(iYmax, iGo1Ymin, iGo1Ymax))) {
		return 'u';
	}
	else if ((iGo1Xmax - iXmin < iXmin - iGo1Xmin ) && (iGo1Ymax - iYmin > iGo1Xmax - iXmin) && (math::isPointBetween(iXmin, iGo1Xmin, iGo1Xmax)) && (math::isPointBetween(iYmin, iGo1Ymin, iGo1Ymax))) {
		return 'r';
	}
	else if ((iXmax - iGo1Xmin < iGo1Xmin - iXmin) && (iGo1Ymax - iYmax > iXmax - iGo1Xmin) && (math::isPointBetween(iXmax, iGo1Xmin, iGo1Xmax)) && (math::isPointBetween(iYmax, iGo1Ymin, iGo1Ymax))) {
		return 'l';
	}
	else if(iGo1Ymax - iYmin == iXmax - iXmin){
		return 'p';
	}
	else {
		return 'o';
	}
}

GameObject::~GameObject()
{
	delete m_Shape;
}