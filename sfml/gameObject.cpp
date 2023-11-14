#include "gameObject.h"
#include "windowManager.h"
#include "gameManager.h"
#include "canon.h"
#include "math.h"
#include "ball.h"
#include "brick.h"

#include <SFML/Graphics.hpp>
#include <iostream>


GameObject::GameObject(float iX, float iY, int iWidth, int iLength , Window* oWindow, GameManager* oGame){
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
	this->setPosition(m_iX, m_iY);
	(*oWindow).m_voGameWindowObjects.push_back(this);
	
}

sf::Shape& GameObject::getShape() {
	return *m_Shape;
}

float GameObject::getX() {
	return m_iX;
}

float GameObject::getY(){
	return m_iY;
}

int GameObject::getWidth(){
	return m_iWidth;
}

int GameObject::getLength(){
	return m_iLength;
}

int GameObject::getRadius(){
	return m_iRadius;
}


void GameObject::setPosition(float fX, float fY, float fRatioX, float fRatioY) {
	m_Shape->setOrigin(fRatioX, fRatioY);
	m_Shape->setPosition(fX, fY);
}



void GameObject::draw(Window& oWindow) {
	oWindow.m_oWindow->draw(getShape());
}

void GameObject::handleCollision(GameObject* oGameObject, float fDeltaTime, Ball* oBall) {
	
	bool isCollide = isColliding(oGameObject);
	bool bIsAlreadyInCollision = false;
	char cSite = oBall->getSide(oGameObject);
	if (std::count(m_voObjectCollide.begin(), m_voObjectCollide.end(), oGameObject)) {
		bIsAlreadyInCollision = true;
	}
	if (isCollide) {
		if (bIsAlreadyInCollision == false)
		{
			onCollisionEnter(cSite, oGameObject, oBall);
		} 
		else{
			onCollisionStay(cSite, oGameObject);
		}
	}
	else {
		if (bIsAlreadyInCollision) {
			onCollisionExit(cSite, oGameObject);
		}
	}
}
void GameObject::onCollisionEnter(char cSite, GameObject* oGameObject, Ball* oBall) {
	m_voObjectCollide.push_back(oGameObject);
	oBall->bounce(cSite);
}
void GameObject::onCollisionStay(char cSite, GameObject* oGameObject) {
	
}
void GameObject::onCollisionExit(char cSite, GameObject* oGameObject) {
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
		iCollidValue = 0;
		return true;
	}
	else {
		iCollidValue = 0;
		return false;
	}
}
char GameObject::getSide(GameObject* oGameObject)
{
	float overlapLR = std::min(m_iY + m_iLength, oGameObject->m_iY + m_iLength) - std::max(m_iY + m_iLength, oGameObject->m_iY + oGameObject->m_iLength);
	float overlapUD = std::min(m_iX + m_iWidth, oGameObject->m_iX + m_iWidth) - std::max(m_iX + m_iWidth, oGameObject->m_iX + oGameObject->m_iWidth);

	if (overlapLR > overlapUD) {
		if (m_iX <= oGameObject->m_iX + oGameObject->m_iWidth and m_iX >= oGameObject->m_iX) {
			return 'r';
		}
		else {
			return 'l';
		}
	}
	else if (overlapLR < overlapUD) {

		if (m_iY + m_iLength >= oGameObject->m_iY and m_iY <= oGameObject->m_iY) {
			return 'u';
		}
		else {
			return 'd';
		}
	}
	else {
		return 'p';
	}
}

GameObject::~GameObject()
{
	delete m_Shape;
}