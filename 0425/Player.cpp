#include "pch.h"
#include "Player.h"

Player::Player(string n, int hp, int att)
	: Obj(n, hp, att)
{
}

void Player::Initialize()
{
}

void Player::Update()
{
	int input;
	cout << "���� ���� (1. �� 2. �� 3. ��) : ";
	cin >> input;

	switch (input) {
	case 1:
		name = "����";
		hp = 100;
		att = 10;
		break;
	case 2:
		name = "������";
		hp = 100;
		att = 10;
		break;
	case 3:
		name = "����";
		hp = 100;
		att = 10;
		break;
	}
}

void Player::Release()
{
}

void Player::SetHp(int hp)
{
	this->hp = hp;
}


