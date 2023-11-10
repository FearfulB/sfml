#pragma once
class InputManager
{
private:
	InputManager();
	static InputManager* pInstance;

public:
	static void Init() 
	{
		InputManager::pInstance = new InputManager();
	}

	static InputManager* Get() 
	{
		return InputManager::pInstance;
	}


	void checkEvent();
	void keyPressed();
};

