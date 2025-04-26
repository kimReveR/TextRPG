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

	void SetHp(int hp) override;			// 플레이어 사망 이후 부활할 때 체력을 되돌린다.
};

