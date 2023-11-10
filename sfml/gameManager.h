#pragma once
#include "windowManager.h"
class GameManager
{
private:
	GameManager();
	static GameManager* pInstance;

public:
	static void Init();
	static GameManager* Get();
	
};