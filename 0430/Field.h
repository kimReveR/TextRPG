#pragma once
#include "Player.h"
#include "Monster.h"

class Field
{
public:
	~Field() { Release(); }
	void Initialize();
	void Update();
	void Release();

	void setPlayer(Player* p) { pPlayer = p; }

private:
	Obj* pPlayer = nullptr;
	Obj* pMonster = nullptr;
};

