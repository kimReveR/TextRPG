#include "pch.h"
#include "Store.h"

Store::Store() : pPlayer(nullptr)
{
	memset(pItem, 0, sizeof(Obj*) * IT_END * IC_END);
}


Store::~Store()
{
	Release();
}

void Store::Initialize()
{
	pItem[IT_WEAPON][BEGGINER] = new Item("초급 무기", 0, 10, 1000);
	pItem[IT_WEAPON][RARE] = new Item("중급 무기", 0, 20, 2000);
	pItem[IT_WEAPON][UNIQUE] = new Item("고급 무기", 0, 30, 3000);

	pItem[IT_ARMOR][BEGGINER] = new Item("초급 방어구", 10, 0, 1000);
	pItem[IT_ARMOR][RARE] = new Item("중급 방어구", 20, 0, 2000);
	pItem[IT_ARMOR][UNIQUE] = new Item("고급 방어구", 30, 0, 3000);
}

void Store::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		pPlayer->Render();

		std::cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			Render(BEGGINER);
			break;

		case 2:
			Render(RARE);
			break;

		case 3:
			Render(UNIQUE);
			break;

		case 4:
			return;
		}

	}
}

void Store::Release()
{
	for (int i = 0; i < IT_END; i++) {
		for (int j = 0; j < IC_END; j++) {
			delete pItem[i][j];
		}
	}
}

void Store::Render(int i)
{
	int iInput(0);


	while (true)
	{
		system("cls");

		pPlayer->Render();

		pItem[IT_WEAPON][i]->Render();
		pItem[IT_ARMOR][i]->Render();

		std::cout << "1. 무기 구매 2. 방어구 구매 3. 전 단계 : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			break;

		case 2:
			break;

		case 3:
			return;
		}


	}
}
