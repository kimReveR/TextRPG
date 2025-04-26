#pragma once
#include "pch.h"
#include "Obj.h"

class Player : public Obj
{
public:
	Player() : Obj("",0,0) {};
	Player(string n, int hp, int att);

	void Initialize() override;
	void Update() override;
	void Release() override;

	void SetHp(int hp) override;			// �÷��̾� ��� ���� ��Ȱ�� �� ü���� �ǵ�����.
};

