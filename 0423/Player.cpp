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
	cout << "1. �� 2. �� 3. �� : ";
	cin >> input;

	switch (input) {
	case WARRIOR:
		setName("����"),	setHp(100),		setAtt(10);
		break;
	case MAGE:
		setName("������"), setHp(100), setAtt(10);
		break;
	case THIEF:
		setName("����"), setHp(100), setAtt(10);
		break;
	}
}

void Player::Release()
{
}

void Player::Render() const
{
	cout << "�̸� : " << CName << endl;
	cout << "ü�� : " << CHp << "\t���ݷ� : " << CAtt << endl;
}
