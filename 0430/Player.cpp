#include "pch.h"
#include "Player.h"

void Player::Initialize()
{
}

void Player::Update()
{
	int input;
	std::cout << "1. ����, 2. ������ 3. ���� : " << std::endl;
	std::cin >> input;

	switch (input) {
	case 1:
		pInfo.strname = "����";
		pInfo.iAtt = 10;
		pInfo.iHp = 100;
		pInfo.iMoney = 10000;
		break;
	case 2:
		pInfo.strname = "������";
		pInfo.iAtt = 10;
		pInfo.iHp = 100;
		pInfo.iMoney = 10000;
		break;
	case 3:
		pInfo.strname = "����";
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
	std::cout << "�̸� : " << pInfo.strname << "\t������ : " << pInfo.iMoney << std::endl;
	std::cout << "ü�� : " << pInfo.iHp << "\t���ݷ� : " << pInfo.iAtt << std::endl;
}
