#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
public:
	float m_iX;
	float m_iY;
	int m_iWidth;
	int m_iLength;
	int m_iRadius;
	bool m_bIsCollide;
	std::vector <GameObject*> m_vObjectCollide;
	sf::Shape* m_Shape;

	GameObject(float iX, float iY, int iWitdh, int iLength);
	GameObject(float iX, float iY, int iRadius);

	sf::Shape& getShape();
	void move(float fDeltaTime, float fDirectionX, float fDirectionY);
	void rotate(float vMousePositionX, float vMousePositionY);
	void handleCollision(GameObject* oGameObject);
	float onCollisionEnter(float  fDeltaTime, float fDirectionX, float fDirectionY, char cSite);
	bool isColliding(GameObject* oGameObject);
	void onCollisionStay();
	void onCollisionExit();
	float bounce(float fDeltaTime, float fDirectionX, float fDirectionY, char cSite);
	char checkSide(GameObject* oGameObject);

	~GameObject();
};
