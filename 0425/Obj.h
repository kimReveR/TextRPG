#pragma once
#include "pch.h"
//#include "Player.h"
//#include "Monster.h"

class Obj
{
protected:					// 플레이어, 몬스터 모두 이름, 체력, 공격력이라는 공통된 변수가 필요
	string name;
	int hp{};
	int att{};

public:
	Obj();
	Obj(string n, int hp, int att);
	Obj(string n, int extra);
	virtual ~Obj() {};

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void SetHp(int hp);			// 플레이어 사망 이후 부활할 때 체력을 되돌린다.

	virtual void Render() const;			// 출력도 여기서 처리

	void SetDamage(int dmg);		// 데미지 입히는것도 처리

	int GetAtt() const;				// 데미지 입힐 때, 공격력을 알아야 하니, get()으로 공격력을 받아옴
	int GetHp() const;				// 플레이어, 몬스터의 체력에 따라 승리, 패배 처리를 해야되서 get()으로 체력을 받아옴
};

