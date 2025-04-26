#include "pch.h"
#include "Fight.h"

Fight::Fight()
{
	player = nullptr;
	monster = nullptr;
}

Fight::~Fight()
{
	delete player;
	delete monster;
}

void Fight::Initialize()
{
	if (!player) {
		player = new Player;
	}
	if (!monster) {
		monster = new Monster;
	}
}

void Fight::Update()
{
	int input;
	while (true) {
		system("cls");
		player->Render();
		monster->Render();
		cout << "1. 공 2. 도 : ";
		cin >> input;

		if (input == 1) {
			player->SetDamage(monster->GetAtt());
			monster->SetDamage(player->GetAtt());
			if (player->GetHp() <= 0) {
				cout << "패배" << endl;
				player->SetHp(100);
				return;
			}
			if (monster->GetHp() <= 0) {
				cout << "승리" << endl;
				return;
			}
			
		}
		if (input == 2) {
			return;
		}

	}
}

void Fight::Release()
{
	
}
