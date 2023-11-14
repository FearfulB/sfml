#pragma once
#include "windowManager.h"
#include "gameObject.h"
#include "canon.h"
#include "ball.h"
#include "brick.h"

class GameManager
{
private:
	GameManager();
	static GameManager* pInstance;

public:

	static void Init();
	static GameManager* Get();
	void mainLoop();
	int grid[40] = {0, 0, 0, 0, 0, 0, 0, 0,
		0, 3, 3, 2, 1, 2, 3, 0,
		0, 3, 3, 1, 1, 1, 2, 0,
		0, 3, 3, 2, 1, 2, 3, 0,
		0, 3, 3, 3, 3, 3, 3, 0 };
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