#include "pch.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(string M_Name, int M_Hp, int M_Att)
{
	setName(M_Name), setHp(M_Hp), setAtt(M_Att);
}

Monster::~Monster()
{
}

void Monster::Render() const
{
	cout << "이름 : " << CName << endl;
	cout << "체력 : " << CHp << "\t공격력 : " << CAtt << endl;
}