#pragma once
#include "Player.h"
#include "Monster.h"

class Field
{
private:
	Player* pPlayer;
	Monster* pMonster;

public :
	Field();
	~Field();

	void Initialize();
	void Update();
	void Release();

	void SetPlayer(Player* player) { pPlayer = player; };

	int Fight();
};

