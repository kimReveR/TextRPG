#include "pch.h"
#include "MainGame.h"

void MainGame::Initialize()
{
	if (!pPlayer) {
		pPlayer = new Player;
	}
	((Player*)pPlayer)->Update();

	if (!pField) {
		pField = new Field;
	}
	pField->setPlayer((Player*)pPlayer);
	pField->Initialize();

	if (!pStore) {
		pStore = new Store;
	}
	pStore->setPlayer((Player*)pPlayer);
	pStore->Initialize();
}

void MainGame::Update()
{
	int input;
	while (true) {
		system("cls");
		pPlayer->Render();
		std::cout << "1. 필드 2. 상점 3. 종료 : ";
		std::cin >> input;

		switch (input) {
		case 1:
			pField->Update();
			break;
		case 2:
			pStore->Update();
			break;
		case 3:
			return;
		}
	}


}

void MainGame::Release()
{
	SAFE_DELETE(pField);
	SAFE_DELETE(pPlayer);
}
