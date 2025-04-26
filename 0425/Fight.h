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

	void SetPlayer(Obj* player) { this->player = player; };					// �÷��̾��� ������ �޾ƿ��� �Լ�
	void SetMonster(Obj* monster) { this->monster = monster; };				// ������ ������ �޾ƿ��� �Լ�

private:
	Obj* player;
	Obj* monster;
};

