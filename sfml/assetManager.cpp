#include "assetManager.h"


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

sf::Texture AssetManager::loadTexture(const char* cPath)
{
    if (m_mTextures.count(cPath)) {
        return m_mTextures[cPath];
    }
    else {
        sf::Texture texture;
        texture.loadFromFile("image.png");
        if (!texture.loadFromFile("image.png")) {
             // error
        }
        m_mTextures.insert(std::pair<std::string, sf::Texture*>(cPath, texture));
        return texture;
    }
    

}