#include "pch.h"
#include "Mob.h"

void Mob::Create(int level)
{
	switch (level) {
	case 1:
		info = Info("초급", 30, 3);
		break;
	case 2:
		info = Info("중급", 60, 6);
		break;
	case 3:
		info = Info("고급", 90, 9);
		break;
	default:
		return;
	}
}

void Mob::print() const
{
	info.print();
}

int Mob::getHp() const
{
	return info.getHp();
}

int Mob::getAtt() const
{
	return info.getAtt();
}

void Mob::takeDamage(int d)
{
	info.takeDamage(d);
}
