#include "pch.h"
#include "Item.h"

void Item::Initialize()
{
}

void Item::Render()
{
	std::cout << "�̸� : " << pInfo.strname << "\t������ : " << pInfo.iMoney << std::endl;
	std::cout << "ü�� : " << pInfo.iHp << "\t���ݷ� : " << pInfo.iAtt << std::endl;
}
