#pragma once
#include "windowManager.h"
#include "gameObject.h"
#include "canon.h"
#include "ball.h"
#include "brick.h"
#include "assetManager.h"


class GameManager
{
private:
	GameManager();
	static GameManager* pInstance;

public:

	static void Init();
	static GameManager* Get();
	bool checkWin();
	

	void mainLoop();
	
	std::vector<int> m_viGrid;
	std::vector<GameObject*> m_voRectCollide;
	std::vector<Ball*> m_voCircleCollide;
	std::vector<Brick*> m_voBrickCollide;
	Window* m_oWindow;

	

	Cannon* m_oCannon;
	GameObject* m_oRect;

	/*GameObject* m_oCircle;*/
	GameObject* m_oWallLeft;
	GameObject* m_oWallRight;
	GameObject* m_oWallTop;

};