#include "pch.h"
#include "MobInfo.h"

string MobInfo::getName()
{
	return Mob_Name;
}

int MobInfo::getHp() const
{
	return Hp;
}

int MobInfo::getAtt() const
{
	return Att;
}

void MobInfo::Info()
{
	cout << "이름 : " << getName() << "\n체력 : "
		<< getHp() << "\t공격력 : " << getAtt() << endl;
}

void MobInfo::takeDamage(int dmg)
{
	Hp = max(0, Hp - dmg);
}

