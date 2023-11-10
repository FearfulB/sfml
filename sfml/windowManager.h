#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class GameObject;

class Window
{
public:
	Window(int iWitdh, int iHeight, std::string sTitle);

	sf::RenderWindow* m_oWindow;
	std::vector<GameObject*> m_voBallsList;


	/*void display(GameObject* oGameObject);*/
};

