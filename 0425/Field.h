#pragma once
#include "Player.h"
#include "Monster.h"
#include "Fight.h"
class Field
{
public:
	Field();
	~Field();

	void Initialize();
	void Update();
	void Release();

	void SetPlayer(Obj* player) { this->player = player; };		// �÷��̾��� ������ �޾ƿ��� �Լ�
	void SetMonster(Obj* monster) { this->monster = monster; };				// ������ ������ �޾ƿ��� �Լ�

private:
	Obj* player;
	Obj* monster;
	Fight* fight;
};

