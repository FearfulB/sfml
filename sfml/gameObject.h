#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	float m_iX;
	float m_iY;
	int m_iWidth;
	int m_iLength;
	int m_iRadius;
	sf::Shape* m_Shape;

	GameObject(float iX, float iY, int iWitdh, int iLength);
	GameObject(float iX, float iY, int iRadius);

	sf::Shape& getShape();
	void move(float fDeltaTime);
	void rotate(float vMousePositionX, float vMousePositionY);
	bool isColliding(GameObject* oGameObject);

};
