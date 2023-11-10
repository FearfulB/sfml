#include "windowManager.h"
#include "gameObject.h"

Window::Window(int iWitdh, int iHeight, std::string sTitle)
{
	m_oWindow = new sf::RenderWindow(sf::VideoMode(iWitdh, iHeight), sTitle);
}
//void WindowManager::display(GameObject* oGameObject) {
//	
//}