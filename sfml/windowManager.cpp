#include "windowManager.h"
#include "gameObject.h"

Window::Window(int iWitdh, int iHeight, std::string sTitle)
{
	m_oWindow = new sf::RenderWindow(sf::VideoMode(iWitdh, iHeight), sTitle);
}
void Window::display() {
	for (int i = 0; i < m_voGameWindowObjects.size(); i++) {
		m_voGameWindowObjects[i]->draw(*this);
	}
	m_oWindow->display();
}