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
	cout << "직업 선택 (1. 전 2. 마 3. 도) : ";
	cin >> input;

	switch (input) {
	case 1:
		name = "전사";
		hp = 100;
		att = 10;
		break;
	case 2:
		name = "마법사";
		hp = 100;
		att = 10;
		break;
	case 3:
		name = "도적";
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


