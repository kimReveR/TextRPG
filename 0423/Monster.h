#pragma once
#include "Character.h"
class Monster : public Character
{

public:
	Monster();
	Monster(string M_Name, int M_Hp, int M_Att);
	~Monster();

public:
	void Render() const override;
	void Damage(int dmg) { CHp -= dmg; };
};


