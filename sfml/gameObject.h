#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
class Window;
class GameManager;

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

	GameObject(float iX, float iY, int iWitdh, int iLength, float fDirectionX, float fDirectionY, Window* oWindow, GameManager* oGame);
	GameObject(float iX, float iY, int iRadius, float fDirectionX, float fDirectionY, Window* oWindow, GameManager* oGame);

	sf::Shape& getShape();
	void setPosition(float fX, float fY, float fRatioX = 0.5f, float fRationY = 0.5f);
	void setRotation(float vMousePositionX, float vMousePositionY, float fRatioX = 0.5f, float fRatioY = 0.5f);
	void draw(Window& oWindow);
	void setDirection(float fX, float fY);
	void move(float fDeltaTime, GameObject* oGameObject);

	void handleCollision(GameObject* oGameObject, float fDeltaPosition);
	void onCollisionEnter( char cSite, GameObject* oGameObject);
	bool isColliding(GameObject* oGameObject);
	void onCollisionStay(char cSite, GameObject* oGameObject);
	void onCollisionExit(char cSite, GameObject* oGameObject);
	void bounce(char cSite, GameObject* oGameObject);
	char checkSide(GameObject* oGameObject);

	~GameObject();
};
