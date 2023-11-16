#include "windowManager.h"
#include "gameObject.h"
#include "assetManager.h"


Window::Window(int iWitdh, int iHeight, std::string sTitle)
{
	m_iWidth = iWitdh;
	m_iHeight = iHeight;
	m_oWindow = new sf::RenderWindow(sf::VideoMode(m_iWidth, m_iHeight), sTitle);
	m_sprite = AssetManager::Get()->sprite("f1.jpg", 1, 1, 0, 0);
}
int Window::getWidth() {
	return m_iWidth;
}
int Window::getHeight() {
	return m_iHeight;
}

void Window::display() {

	m_oWindow->draw(*m_sprite);
	

	for (int i = 0; i < m_voGameWindowObjects.size(); i++) {
		m_voGameWindowObjects[i]->draw(*this);
	}
	for (int i = 0; i < m_voSprite.size(); i++) {
		m_oWindow->draw(*m_voSprite[i]);
	}
	m_oWindow->display();
}

void Window::displayWin() {  
	sf::Text* text = AssetManager::Get()->text("starborn/Starborn.ttf","You Win",25,200,300);
	m_oWindow->draw(*text);
}
