#pragma once
#include "pch.h"

#include "Player.h"
#include "Monster.h"

class Fight
{
private:
	Player* m_tPlayer = nullptr;
	Monster* m_tMonster = nullptr;
public:
	Fight();
	~Fight();

	void Initialize();
	void Update();

	void setPlayer(Player* player) { m_tPlayer = player; };
	void setMonster(Monster* monster) {m_tMonster = monster; };
};


