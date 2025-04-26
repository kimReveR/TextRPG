#include "pch.h"
#include "Player.h"

Player::Player()
{
	setName("");
	setHp(0);
	setAtt(0);
}

Player::~Player()
{
}

void Player::Initialize()
{
}

void Player::Update()
{
	int input;
	cout << "1. 전 2. 마 3. 도 : ";
	cin >> input;

	switch (input) {
	case WARRIOR:
		setName("전사"),	setHp(100),		setAtt(10);
		break;
	case MAGE:
		setName("마법사"), setHp(100), setAtt(10);
		break;
	case THIEF:
		setName("도적"), setHp(100), setAtt(10);
		break;
	}
}

void Player::Release()
{
}

void Player::Render() const
{
	cout << "이름 : " << CName << endl;
	cout << "체력 : " << CHp << "\t공격력 : " << CAtt << endl;
}
