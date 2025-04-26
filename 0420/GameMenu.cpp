#include "pch.h"
#include "GameMenu.h"
#include "Save.h"
#include "Global.h"

class Info;

GameMenu::GameMenu()
{
}

GameMenu::~GameMenu()
{
}

void GameMenu::Initialize()
{
}

void GameMenu::Update(const Info& player)
{
	while (true) {
		system("cls");
		player.print();
		cout << "1. 필드 2. 저장 3. 종료 7. 인벤토리 : ";
		int input;
		cin >> input;
		switch (input) {
		case 1: {
			return;
		}
		case 2: {
			Save save;
			save.Update("../sav.bin", player, g_inventory);
			break;
		}
		case 3:
			exit(0);
		case 7:
			g_inventory.List();
			system("pause");
			break;
		default:
			break;
		}
	}

}

void GameMenu::Release()
{
}
