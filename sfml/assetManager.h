#pragma once
class AssetManager
{

private:
	AssetManager();
	static AssetManager* pInstance;

public:

	static void Init();
	static AssetManager* Get();
};

