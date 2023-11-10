#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
class Window;

class GameObject
{
public:
	float m_iX;
	float m_iY;
	int m_iWidth;
	int m_iLength;
	int m_iRadius;
	float m_fDirectionX;
	float m_fDirectionY;
	std::vector <GameObject*> m_voObjectCollide;
	
	sf::Shape* m_Shape;

	GameObject(float iX, float iY, int iWitdh, int iLength, Window* oWindow);
	GameObject(float iX, float iY, int iRadius, float fDirectionX, float fDirectionY, Window* oWindow);

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
