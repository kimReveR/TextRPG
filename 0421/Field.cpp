#include "pch.h"
#include "Field.h"

Field::Field()
{
	pPlayer = nullptr;
	pMonster = nullptr;
}

Field::~Field()
{
	Release();
}

void Field::Initialize()
{
}

void Field::Update()
{
	int input;
	while (true) {
		system("cls");
		pPlayer->Render();
		cout << "1. 초 2. 중 3. 고 4. 뒤로 : ";
		cin >> input;

		switch (input) {
		case 1:
			pMonster = new Monster("초급", 30, 3);
			break;
		case 2:
			pMonster = new Monster("중급", 60, 6);
			break;
		case 3:
			pMonster = new Monster("고급", 90, 9);
			break;
		case 4:
			return;
		}

		int result = Fight();
		if (result == 1) {
			pPlayer->SetHp(100);
		}
	}
}

void Field::Release()
{
	SAFE_DELETE(pMonster);
}

int Field::Fight()
{
	int input;
	while (true) {
		system("cls");
		pPlayer->Render();
		pMonster->Render();
		cout << "1. 공격 2. 도망 : ";
		cin >> input;

		if (input == 1) {
			pPlayer->Battle(pMonster->GetInfo().iAttack);
			pMonster->Battle(pPlayer->GetInfo().iAttack);

			if (pPlayer->GetInfo().iHp <= 0) {
				cout << "패배" << endl;
				return 1;
			}
			if (pMonster->GetInfo().iHp <= 0) {
				cout << "승리" << endl;
				return 0;
			}
		}
		else if (input == 2) {
			return 0;
		}
	}
}
