#include "pch.h"
#include "Monster.h"

void Monster::Initialize()
{
}

void Monster::Render()
{
	std::cout << "�̸� : " << pInfo.strname << std::endl;
	std::cout << "ü�� : " << pInfo.iHp << "\t���ݷ� : " << pInfo.iAtt << std::endl;
}
