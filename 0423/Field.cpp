#include "pch.h"
#include "Field.h"

Field::Field()
{
	m_tPlayer = nullptr;
	m_tMonster = nullptr;
	m_tFight = nullptr;
}

Field::~Field()
{
}

void Field::Initialize()
{
	setPlayer(m_tPlayer);
	
}

void Field::Update()
{
	int input;
	while (true) {
		m_tPlayer->Render();
		cout << "1. �� 2. �� 3. �� 4. �� : ";
		cin >> input;
		switch (input) {
		case 1:
			m_tMonster = new Monster("��", 30, 3);
			break;
		case 2:
			m_tMonster = new Monster("��", 60, 6);
			break;
		case 3:
			m_tMonster = new Monster("��", 90, 9);
			break;
		case 4:
			return;
		}
		if (!m_tFight) {
			m_tFight = new Fight();
		}
		m_tFight->setPlayer(m_tPlayer);
		m_tFight->setMonster(m_tMonster);
		m_tFight->Initialize();
		m_tFight->Update();
		//Fight_Init();
	}
}

void Field::Release()
{
	delete m_tMonster;
	delete m_tPlayer;
	delete m_tFight;
}

void Field::Fight_Init()
{
	int input;
	while (true) {
		m_tPlayer->Render();
		m_tMonster->Render();

		cout << "1. �� 2. ���� : ";
		cin >> input;

		if (input == 1) {
			m_tPlayer->Damage(m_tMonster->getAtt());
			m_tMonster->Damage(m_tPlayer->getAtt());
			if (m_tPlayer->getHp() <= 0) {
				cout << "�й�" << endl;
				m_tPlayer->setHp(100);
				return;
			}
			if (m_tMonster->getHp() <= 0) {
				cout << "�¸�" << endl;
				return;
			}
		}
		else if (input == 2) {
			return;
		}
	}


}
