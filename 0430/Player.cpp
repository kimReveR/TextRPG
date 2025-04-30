#include "pch.h"
#include "Player.h"

void Player::Initialize()
{
}

void Player::Update()
{
	int input;
	std::cout << "1. 전사, 2. 마법사 3. 도적 : " << std::endl;
	std::cin >> input;

	switch (input) {
	case 1:
		pInfo.strname = "전사";
		pInfo.iAtt = 10;
		pInfo.iHp = 100;
		pInfo.iMoney = 10000;
		break;
	case 2:
		pInfo.strname = "마법사";
		pInfo.iAtt = 10;
		pInfo.iHp = 100;
		pInfo.iMoney = 10000;
		break;
	case 3:
		pInfo.strname = "도적";
		pInfo.iAtt = 10;
		pInfo.iHp = 100;
		pInfo.iMoney = 10000;
		break;
	}
}

void Player::Release()
{
}

void Player::Render()
{
	std::cout << "이름 : " << pInfo.strname << "\t소지금 : " << pInfo.iMoney << std::endl;
	std::cout << "체력 : " << pInfo.iHp << "\t공격력 : " << pInfo.iAtt << std::endl;
}
