#include "pch.h"
#include "Monster.h"

void Monster::Initialize()
{
}

void Monster::Render()
{
	std::cout << "이름 : " << pInfo.strname << std::endl;
	std::cout << "체력 : " << pInfo.iHp << "\t공격력 : " << pInfo.iAtt << std::endl;
}
