#include "assetManager.h"
#include <iostream>



AssetManager::AssetManager() {

}

AssetManager* AssetManager::pInstance = nullptr;

void AssetManager::Init()
{
    AssetManager::pInstance = new AssetManager();
}

AssetManager* AssetManager::Get()
{
    return AssetManager::pInstance;
}

sf::Sprite* AssetManager::sprite(const char* cPath, int iSizeX, int iSizeY, int iX, int iY)
{
    if (m_mSprite.count(cPath)) {
        return m_mSprite[cPath];
    }
    else {
        sf::Texture* texture = new sf::Texture();
        (*texture).loadFromFile(cPath);
        if (!(*texture).loadFromFile(cPath)) {
             // error
        }
		sf::Sprite* sprite = new sf::Sprite();
		(*sprite).setTexture(*texture);
		(*sprite).setScale(sf::Vector2f(iSizeX, iSizeY));
		(*sprite).setPosition(sf::Vector2f(iX, iY));
		m_mSprite.insert(std::pair<std::string, sf::Sprite*>(cPath, sprite));
        return sprite;
    }
}

sf::Text* AssetManager::text(const char* cPath, const char* cMessage, int size, int iX, int iY) {
	if (m_mText.count(cMessage)) {
		return m_mText[cMessage];
	}
	else {
		sf::Text* text = new sf::Text();
		(*m_font).loadFromFile(cPath);
		
		
		if (!(*m_font).loadFromFile(cPath))
		{
			std::cout << "Error ";
			
		}
		(*text).setFont(*m_font);

		
		(*text).setString(cMessage);

		
		(*text).setCharacterSize(size); 

		(*text).setPosition(iX, iY);

		
		(*text).setFillColor(sf::Color::Red);
		
		
		
		m_mText.insert(std::pair<std::string, sf::Text*>(cMessage, text));
		return text;
	}
}

