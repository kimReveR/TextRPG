#include "pch.h"
#include "Field.h"

void Field::Initialize()
{
	/*if (!pMonster) {
		pMonster = new Monster;
	}
	pMonster->Initialize();*/
}

void Field::Update()
{
	int input;
	while (true) {
		system("cls");
		pPlayer->Render();
		std::cout << "1. �� 2. �� 3. �� 4. �ڷ� : ";
		std::cin >> input;

		switch (input) {
		case 1:
			pMonster = new Monster("�ʱ�", 30, 3);
			break;
		case 2:
			pMonster = new Monster("�߱�", 60, 6);
			break;
		case 3:
			pMonster = new Monster("���", 90, 9);
			break;
		case 4:
			return;
		}

		int fight;
		while (true) {
			system("cls");
			pPlayer->Render();
			pMonster->Render();
			std::cout << "1. ���� 2. ���� : ";
			std::cin >> fight;

			if (fight == 1) {
				pPlayer->setDmg(pMonster->getAtt());
				pMonster->setDmg(pPlayer->getAtt());
				if (pMonster->getHp() <= 0) {
					std::cout << "�¸�" << std::endl;
					break;
				}
				if (pPlayer->getHp() <= 0) {
					std::cout << "�й�" << std::endl;
					pPlayer->SetHp(100);
					break;
				}
			}
			if (fight == 2) {
				break;
			}
		}
	}
}

void Field::Release()
{
	SAFE_DELETE(pMonster);
}
