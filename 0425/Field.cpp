#include "pch.h"
#include "Field.h"

Field::Field()
{
	player = nullptr;
	monster = nullptr;
	fight = nullptr;
}

Field::~Field()
{
	Release();
}

void Field::Initialize()
{
	if (!monster) {
		monster = new Monster;
	}

}

void Field::Update()
{
	int input;
	while (true) {
		system("cls");
		player->Render();
		cout << "1. �� 2. �� 3. �� 4. �� : ";
		cin >> input;
		switch (input) {
		case 1:
			if (monster)
			{
				delete monster;
			}
			monster = new Monster("��", 30, 3);
			break;
		case 2:
			if (monster)
			{
				delete monster;
			}
			monster = new Monster("��", 60, 6);
			break;
		case 3:
			if (monster)
			{
				delete monster;
			}
			monster = new Monster("��", 90, 9);
			break;

		case 4:
			return;
		}
		if (!fight) {
			fight = new Fight;
		}
		fight->SetPlayer(player);
		fight->SetMonster(monster);
		fight->Initialize();
		fight->Update();
	}
}

void Field::Release()
{
	delete player;
	delete monster;
	delete fight;
}
