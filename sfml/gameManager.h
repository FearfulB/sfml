#pragma once
#include "windowManager.h"
#include "gameObject.h"
class GameManager
{
private:
	GameManager();
	static GameManager* pInstance;

public:

	static void Init();
	static GameManager* Get();
	void mainLoop();
	std::vector<GameObject*> m_voRectCollide;
	std::vector<GameObject*> m_voCircleCollide;
	Window* m_oWindow;
	
	GameObject* m_oRect;
	GameObject* m_oCanon;
	GameObject* m_oCircle;
	GameObject* m_oWallLeft;
	GameObject* m_oWallRight;
	GameObject* m_oWallTop;
};