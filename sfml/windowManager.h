#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class GameObject;

class Window
{
public:
	int m_iWidth;
	int m_iHeight;
	Window(int iWitdh, int iHeight, std::string sTitle);
	sf::RenderWindow* m_oWindow;
	std::vector<GameObject*> m_voGameWindowObjects;
	std::vector<sf::Sprite*> m_voSprite;
	sf::Sprite* m_sprite;
	/*dans le gameManager mettre le rectCollide et le circle*/

	int getWidth();
	int getHeight();
	void display(int iNumberBall);
	void displayWin();
	void displayLose();
	void displayNumberBall(int iNumberBall);
};
