#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iLength;
	int m_iRadius;
	sf::Shape* m_Shape;

	GameObject(int iX, int iY, int iWitdh, int iLength);
	GameObject(int iX, int iY, int iRadius);

	sf::Shape& getShape();
	void ballMovement();
};
