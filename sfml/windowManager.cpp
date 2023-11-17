#include "windowManager.h"
#include "gameObject.h"
#include "assetManager.h"

Window::Window(int iWitdh, int iHeight, std::string sTitle)
{
	m_iWidth = iWitdh;
	m_iHeight = iHeight;
	m_oWindow = new sf::RenderWindow(sf::VideoMode(m_iWidth, m_iHeight), sTitle);
	m_sprite = AssetManager::Get()->sprite("img/f1.jpg", 1, 1, 10, 0);
}
int Window::getWidth() {
	return m_iWidth;
}
int Window::getHeight() {
	return m_iHeight;
}

void Window::display(int iNumberBall) {
	m_oWindow->draw(*m_sprite);
	displayNumberBall(iNumberBall);
	for (int i = 0; i < m_voGameWindowObjects.size(); i++) {
		if (m_voGameWindowObjects[i]->m_iX != 310 && m_voGameWindowObjects[i]->m_iY != 410) {
			m_voGameWindowObjects[i]->draw(*this);
		}
		
	}
	for (int i = 0; i < m_voSprite.size(); i++) {
		m_oWindow->draw(*m_voSprite[i]);
	}

	m_oWindow->display();
}

void Window::displayWin() {
	m_oWindow->draw(*m_sprite);
	sf::Text* text = AssetManager::Get()->text("starborn/Starborn.ttf", "You Win", 50, 150, 150);
	m_oWindow->draw(*text);
	m_oWindow->display();
}

void Window::displayLose() {
	m_oWindow->draw(*m_sprite);
	sf::Text* text = AssetManager::Get()->text("starborn/Starborn.ttf", "You Lose", 50, 150, 150);
	m_oWindow->draw(*text);
	m_oWindow->display();
}
void Window::displayNumberBall(int iNumberBall) {
	m_oWindow->draw(*m_sprite);
	sf::Text* text = AssetManager::Get()->text("starborn/Starborn.ttf",std::to_string(iNumberBall).c_str(), 30, 590, 10);
	m_oWindow->draw(*text);
	/*m_oWindow->display();*/
}