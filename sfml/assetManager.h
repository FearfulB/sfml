#pragma once
#include <SFML/Graphics.hpp>
class AssetManager
{

private:
	AssetManager();
	static AssetManager* pInstance;
	


public:
	
	static void Init();
	static AssetManager* Get();
	sf::Sprite* sprite(const char* cPath, int iSizeX, int iSizeY, int iX, int iY);
	sf::Font* m_font = new sf::Font;

	sf::Text* text(const char* cPath, const char* cMessage, int size, int iX, int iY);
	std::map<std::string, sf::Sprite*> m_mSprite;
	std::map<std::string, sf::Text*> m_mText;
	
};

