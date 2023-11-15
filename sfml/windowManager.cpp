#include "windowManager.h"
#include "gameObject.h"

Window::Window(int iWitdh, int iHeight, std::string sTitle)
{
	m_iWidth = iWitdh;
	m_iHeight = iHeight;
	m_oWindow = new sf::RenderWindow(sf::VideoMode(m_iWidth, m_iHeight), sTitle);
}
int Window::getWidth() {
	return m_iWidth;
}
int Window::getHeight() {
	return m_iHeight;
}

void Window::display() {
	for (int i = 0; i < m_voGameWindowObjects.size(); i++) {
		m_voGameWindowObjects[i]->draw(*this);
	}
	m_oWindow->display();
}
