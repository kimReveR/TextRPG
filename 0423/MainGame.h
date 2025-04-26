#pragma once
#include "Player.h"
#include "Field.h"

class MainGame
{
public:
	MainGame();
	~MainGame();

	void Initialize();
	void Update();
	void Release();

private:
	Player* m_tPlayer;
	Field* m_tField;
};

