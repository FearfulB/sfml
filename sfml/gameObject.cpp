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

void GameObject::ballMovement() {
	/*m_shape.x = *delta_time*+10.f*/
	/*m_shape.y = *delta_time*+10.f*/
}