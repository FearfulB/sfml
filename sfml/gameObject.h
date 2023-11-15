#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Ball;
class Window;
class Cannon;
class GameManager;
class Brick;

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

	GameObject(float iX, float iY, int iWitdh, int iLength, Window* oWindow, GameManager* oGame);
	GameObject(float iX, float iY, int iRadius, Window* oWindow, GameManager* oGame);

	float getX();
	float getY();
	int getWidth();
	int getLength();
	int getRadius();

	sf::Shape& getShape();
	void setPosition(float fX, float fY, float fRatioX = 0.5f, float fRatioY = 0.5f);
	void draw(Window& oWindow);
	virtual void handleCollision(GameObject* oGameObject, float fDeltaTime, GameManager* oGame);
	virtual void onCollisionEnter(char cSide, GameManager* oGame, GameObject* oGameObject);
	void onCollisionStay(char cSite, GameObject* oGameObject);
	void onCollisionExit(char cSite, GameObject* oGameObject);
	bool isColliding(GameObject* oGameObject);
	char getSide(GameObject* oGameObject);

	~GameObject();
};
