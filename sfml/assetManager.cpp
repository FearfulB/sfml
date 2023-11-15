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