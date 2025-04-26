#include "pch.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(string name, int hp, int att)
{
	m_tMonster.stdName = name;
	m_tMonster.iHp = hp;
	m_tMonster.iAttack = att;
}

Monster::~Monster()
{
}

void Monster::Initialize()
{
}

void Monster::Update()
{
}

void Monster::Release()
{
}

INFO Monster::GetInfo()
{
	return m_tMonster;
}

void Monster::Render()
{
	cout << "�̸� : " << m_tMonster.stdName << endl;
	cout << "ü�� : " << m_tMonster.iHp << "\t���ݷ� : " << m_tMonster.iAttack << endl;
}

void Monster::Battle(int i)
{
	m_tMonster.iHp -= i;
}
