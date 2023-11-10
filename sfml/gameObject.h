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
	float m_fDirectionX;
	float m_fDirectionY;
	std::vector <GameObject*> m_vObjectCollide;
	sf::Shape* m_Shape;

	GameObject(float iX, float iY, int iWitdh, int iLength, float fDirectionX, float fDirectionY);
	GameObject(float iX, float iY, int iRadius);

	sf::Shape& getShape();
	void move(float fDeltaTime, GameObject* oGameObject);
	void rotate(float vMousePositionX, float vMousePositionY);
	void handleCollision(GameObject* oGameObject, float fDeltaPosition);
	void onCollisionEnter( char cSite, GameObject* oGameObject);
	bool isColliding(GameObject* oGameObject);
	void onCollisionStay(char cSite, GameObject* oGameObject);
	void onCollisionExit(char cSite, GameObject* oGameObject);
	void bounce(char cSite, GameObject* oGameObject);
	char checkSide(GameObject* oGameObject);

	~GameObject();
};
