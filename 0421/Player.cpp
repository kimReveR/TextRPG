#include "pch.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Initialize()
{
}

void Player::Update()
{
	cout << "1. ���� 2. ������ 3. ���� : ";
	int input;
	cin >> input;

	switch (input) {
	case 1:
		m_tInfo.stdName = "����";
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;
	case 2:
		m_tInfo.stdName = "������";
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;
	case 3:
		m_tInfo.stdName = "����";
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;
	}
}

void Player::Release()
{
}

void Player::Render()
{
	cout << "�̸� : " << m_tInfo.stdName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}

void Player::Battle(int i)
{
	m_tInfo.iHp -= i;
}

INFO Player::GetInfo()
{
	return m_tInfo;
}

void Player::SetHp(int iHp)
{
	this->m_tInfo.iHp = iHp;
}
