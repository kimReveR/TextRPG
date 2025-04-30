#include "pch.h"
#include "Item.h"

void Item::Initialize()
{
}

void Item::Render()
{
	std::cout << "이름 : " << pInfo.strname << "\t소지금 : " << pInfo.iMoney << std::endl;
	std::cout << "체력 : " << pInfo.iHp << "\t공격력 : " << pInfo.iAtt << std::endl;
}
