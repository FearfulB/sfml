#pragma once
class InputManager
{
private:
	InputManager();
	static InputManager* pInstance;

public:
	static void Init();
	

	static InputManager* Get();
	


	void checkEvent();
	void keyPressed();
};

