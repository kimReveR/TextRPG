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
	cout << "�̸� : " << CName << endl;
	cout << "ü�� : " << CHp << "\t���ݷ� : " << CAtt << endl;
}