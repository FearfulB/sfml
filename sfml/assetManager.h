#pragma once
#include <SFML/Graphics.hpp>
class AssetManager
{

private:
	AssetManager();
	static AssetManager* pInstance;
	std::map<std::string, sf::Texture*> m_mTextures;


public:

	static void Init();
	static AssetManager* Get();
	sf::Texture loadTexture(const char* cPath);
};

