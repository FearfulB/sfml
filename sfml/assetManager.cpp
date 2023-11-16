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
	if (m_mTexture.count(cPath)) {
		return setTexture(m_mTexture[cPath], iSizeX, iSizeY, iX, iY);
	}
	else {
		sf::Texture* texture = new sf::Texture();
		(*texture).loadFromFile(cPath);
		m_mTexture.insert(std::pair<std::string, sf::Texture*>(cPath, texture));
		if (!(*texture).loadFromFile(cPath)) {
			// error
		}
		return setTexture(texture, iSizeX, iSizeY, iX, iY);
	}
}

sf::Sprite* AssetManager::setTexture(sf::Texture* texture, int iSizeX, int iSizeY, int iX, int iY) {
	sf::Sprite* sprite = new sf::Sprite();
	(*sprite).setTexture(*texture);
	(*sprite).setScale(sf::Vector2f(iSizeX, iSizeY));
	(*sprite).setPosition(sf::Vector2f(iX, iY));
	return sprite;
}

sf::Text* AssetManager::text(const char* cPath, const char* cMessage, int size, int iX, int iY) {

	if (m_mFont.count(cPath)) {
		return setText(m_mFont[cPath], cMessage, size, iX, iY);

	}
	else {
		(*m_font).loadFromFile(cPath);
		if (!(*m_font).loadFromFile(cPath))
		{
			std::cout << "Error ";
		}
		m_mFont.insert(std::pair<std::string, sf::Font*>(cPath, m_font));
		return setText(m_font, cMessage, size, iX, iY);

	}
}

sf::Text* AssetManager::setText(sf::Font* font, const char* cMessage, int size, int iX, int iY) {
	sf::Text* text = new sf::Text();
	(*text).setFont(*m_font);
	(*text).setString(cMessage);
	(*text).setCharacterSize(size);
	(*text).setPosition(iX, iY);
	(*text).setFillColor(sf::Color::Red);
	return text;
}

