#include "pch.h"
#include "Obj.h"

Obj::Obj()
{
	name = ""; hp = 0; att = 0;
}

Obj::Obj(string n, int hp, int att) : name(n), hp(hp), att(att)
{
	//name = n;
	//hp = hp;
	//att = att;
}

Obj::Obj(string n, int extra)
{
}

void Obj::Initialize()
{
}

void Obj::Update()
{
}

void Obj::Release()
{
}

void Obj::SetHp(int hp)
{
}

void Obj::Render() const
{
	cout << "�̸� : " << name << endl;
	cout << "ü�� : " << hp << "\t���ݷ� : " << att << endl;
}

void Obj::SetDamage(int dmg)
{
	hp -= dmg;
}


int Obj::GetAtt() const
{
	return att;
}

int Obj::GetHp() const
{
	return hp;
}