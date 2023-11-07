#include "gameObject.h"

#include <SFML/Graphics.hpp>


GameObject::GameObject(int iX, int iY, int iWidth, int iLength)
{
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWidth;
	m_iLength = iLength;
	m_Shape = new sf::RectangleShape(sf::Vector2f(m_iLength, m_iWidth));
	m_Shape->setPosition(m_iX, m_iY);
	m_Shape->setOrigin(10,0);

}
GameObject::GameObject(int iX, int iY, int iRadius) {
	m_iX = iX;
	m_iY = iY;
	m_iRadius = iRadius;
	m_Shape = new sf::CircleShape(m_iRadius);
	m_Shape->setPosition(m_iX, m_iY);
}
sf::Shape& GameObject::getShape() {
	return *m_Shape;
}

void GameObject::ballMovement(float fDeltaTime) {
	m_iX = 10 * fDeltaTime * 10.f;
	m_iY = 10 * fDeltaTime * 10.f;
}

void GameObject::canonRotation(int vMousePosition) {
	if (vMousePosition <= 832) {
		m_Shape->setRotation(832);
	}
	else if (vMousePosition >= 970){
		m_Shape->setRotation(970);
	}
	else {
		m_Shape->setRotation(vMousePosition);
	}
}