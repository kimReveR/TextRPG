#pragma once
#include "Player.h"
#include "Monster.h"
class Fight
{
public:
	Fight();
	~Fight();

	void Initialize();
	void Update();
	void Release();

	void SetPlayer(Obj* player) { this->player = player; };					// 플레이어의 정보를 받아오는 함수
	void SetMonster(Obj* monster) { this->monster = monster; };				// 몬스터의 정보를 받아오는 함수

private:
	Obj* player;
	Obj* monster;
};

