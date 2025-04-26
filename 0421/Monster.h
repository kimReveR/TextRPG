#pragma once
#include "Define.h"

class Monster
{
private:
	INFO m_tMonster;

public:
	Monster();
	Monster(string name, int hp, int att);
	~Monster();

	void Initialize();
	void Update();
	void Release();

	INFO GetInfo();
	void Render();
	void Battle(int i);
};

