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

void GameObject::move(float fDeltaTime, float fDirectionX, float fDirectionY) {
	m_iX += fDirectionX * fDeltaTime * 60.f;
	m_iY += fDirectionY * fDeltaTime * 60.f;
	m_Shape->setPosition(m_iX, m_iY);
}

void GameObject::rotate(float vMousePositionX, float vMousePositionY) {
	
	int mouseAngle = -atan2(vMousePositionX - m_iX, vMousePositionY - m_iY) * 180 / 3.1459;

	m_Shape->setRotation(mouseAngle);

}

bool GameObject::isColliding(GameObject* oGameObject) {
	if (m_iWidth < oGameObject->m_iWidth) {
		std::cout << "e" << std::endl;
		if (math::isPointBetween(m_iX, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iWidth)
			|| math::isPointBetween(m_iX + m_iWidth, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iWidth)) {
			if (m_iLength < oGameObject->m_iLength) {
				if (math::isPointBetween(m_iY, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iLength)
					|| math::isPointBetween(m_iY + m_iLength, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iLength)) {
					return true;
				}
			}
			else {
				if (math::isPointBetween(oGameObject->m_iY, m_iY, m_iY + m_iLength)
					|| math::isPointBetween(oGameObject->m_iY + oGameObject->m_iLength, m_iY, m_iLength)) {
					return true;
				}
			}
		}
	}
	else {
		if (math::isPointBetween(oGameObject->m_iX, m_iX, m_iX + m_iWidth)
			|| math::isPointBetween(oGameObject->m_iX + oGameObject->m_iWidth, m_iX, m_iX + m_iWidth)) {
			if (m_iLength < oGameObject->m_iLength) {
				if (math::isPointBetween(m_iY, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iLength)
					|| math::isPointBetween(m_iY + m_iLength, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iLength)) {
					return true;
				}
			}
			else {
				if (math::isPointBetween(oGameObject->m_iY, m_iY, m_iY + m_iLength)
					|| math::isPointBetween(oGameObject->m_iY + oGameObject->m_iLength, m_iY, m_iLength)) {
					return true;
				}
			}
		}
	}
}

float GameObject::bounce(float  fDeltaTime, float fDirectionX, float fDirectionY) {
	/*a changer si l on veux faire le bonus avec les balles qui collisionne*/
	return fDirectionX = -fDirectionX;
}

GameObject::~GameObject()
{
	delete m_Shape;
}