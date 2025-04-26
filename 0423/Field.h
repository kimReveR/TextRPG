#pragma once

#include "Player.h"
#include "Monster.h"
#include "Fight.h"
class Field
{
protected:
	Player* m_tPlayer;
	Monster* m_tMonster;
	Fight* m_tFight;
public:
	Field();
	~Field();

	void Initialize();
	void Update();
	void Release();

	void setPlayer(Player* player) { m_tPlayer = player; };
	
	void Fight_Init();
};

