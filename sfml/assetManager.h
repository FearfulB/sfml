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
	sf::Font* m_font = new sf::Font;
	std::map<std::string, sf::Texture*> m_mTexture;
	std::map<std::string, sf::Font*> m_mFont;
	sf::Sprite* sprite(const char* cPath, int iSizeX, int iSizeY, int iX, int iY);
	sf::Sprite* setTexture(sf::Texture* texture, int iSizeX, int iSizeY, int iX, int iY);
	sf::Text* text(const char* cPath, const char* cMessage, int size, int iX, int iY);
	sf::Text* setText(sf::Font* font, const char* cMessage, int size, int iX, int iY);


};

