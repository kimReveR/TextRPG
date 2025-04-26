#pragma once
#include "Player.h"
#include "Field.h"

class MainGame
{
public:
	MainGame();
	~MainGame();
public:
	void Initialize();
	void Update();
	void Release();

private:
	Player* p_Player;
	Field* p_Field;
};

