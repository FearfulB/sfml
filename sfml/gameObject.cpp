#include "gameObject.h"
#include "math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject(float iX, float iY, int iWidth, int iLength, float fDirectionX, float fDirectionY)
{
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWidth;
	m_iLength = iLength;
	m_fDirectionX = fDirectionX;
	m_fDirectionY = fDirectionY;
	m_Shape = new sf::RectangleShape(sf::Vector2f(m_iLength, m_iWidth));
	m_Shape->setPosition(m_iX, m_iY);
}
GameObject::GameObject(float iX, float iY, int iRadius) {
	m_iX = iX;
	m_iY = iY;
	m_iRadius = iRadius;
	m_iLength = 2 * m_iRadius;
	m_iWidth = 2 * m_iRadius;
	m_Shape = new sf::CircleShape(m_iRadius);
	m_Shape->setPosition(m_iX, m_iY);
}
sf::Shape& GameObject::getShape() {
	return *m_Shape;
}

void GameObject::move(float fDeltaTime, GameObject* oGameObject) {
	/*std::cout << m_fDirectionX << std::endl;*/
	m_iX += oGameObject->m_fDirectionX * fDeltaTime * 60.f;
	m_iY += oGameObject->m_fDirectionY * fDeltaTime * 60.f;
	m_Shape->setPosition(m_iX, m_iY);
}

void GameObject::rotate(float vMousePositionX, float vMousePositionY) {
	
	int mouseAngle = -atan2(vMousePositionX - m_iX, vMousePositionY - m_iY) * 180 / 3.1459;

	m_Shape->setRotation(mouseAngle);

}


void GameObject::handleCollision(GameObject* oGameObject, float fDeltaTime) {
	
	bool isCollide = isColliding(oGameObject);
	bool bIsAlreadyInCollision = false;
	
	char cSite = this->checkSide(oGameObject);
	for (int i = 0; i < m_vObjectCollide.size(); i++) {
		if (m_vObjectCollide[i] == oGameObject) {
			bIsAlreadyInCollision = true;
			break;
		}
	}
	if (isCollide) {
		if (bIsAlreadyInCollision == false)
		{
			onCollisionEnter(cSite, oGameObject);
			move(fDeltaTime, oGameObject);
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
void GameObject::onCollisionEnter(char cSite, GameObject* oGameObject) {
	m_vObjectCollide.push_back(oGameObject);
	bounce(cSite, oGameObject);
}
void GameObject::onCollisionStay(char cSite, GameObject* oGameObject) {
	
}
void GameObject::onCollisionExit(char cSite, GameObject* oGameObject) {
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
	float overlapLR = std::min(m_iY + m_iLength, oGameObject->m_iY+ m_iLength) - std::max(m_iY + m_iLength, oGameObject->m_iY + oGameObject->m_iLength);
	float overlapUD = std::min(m_iX + m_iWidth, oGameObject->m_iX+ m_iWidth) - std::max(m_iX + m_iWidth, oGameObject->m_iX + oGameObject->m_iWidth);

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
}
void GameObject::bounce( char cSite ,GameObject* oGameObject) {
	
	/*a changer si l on veux faire le bonus avec les balles qui collisionne*/
	if(cSite == 'l' || cSite =='r') {
		oGameObject->m_fDirectionX = - oGameObject->m_fDirectionX;
	}
	else{
		oGameObject->m_fDirectionY = - oGameObject->m_fDirectionY;
	} 
		
}
void GameObject::removeObject(GameObject* oGameObject) {
	//if (m_iY > 640 || m_iX + m_iLength < 0 || m_iX > 480) {
	//	delete 		
	//}

}
GameObject::~GameObject()
{
	delete m_Shape;
}