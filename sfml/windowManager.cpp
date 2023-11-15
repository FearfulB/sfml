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

void Window::displayWin() {
    sf::Font font; 
    sf::Text text;
    font.loadFromFile("starborn/Starborn.ttf");

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("You Win");

    // set the character size
    text.setCharacterSize(25); // in pixels, not points!

    text.setPosition(200, 300);

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold );

    m_oWindow->draw(text);

    



    

}
