#include "pch.h"
#include "MainGame.h"

MainGame::MainGame()
{
	p_Player = nullptr;
	p_Field = nullptr;
}

MainGame::~MainGame()
{
}

void MainGame::Initialize()
{
	if (!p_Player) {
		p_Player = new Player;
	}
	p_Player->Update();

	if (!p_Field) {
		p_Field = new Field;
	}
	p_Field->Initialize();
	p_Field->SetPlayer(p_Player);
}

void MainGame::Update()
{

	int input;
	while (true) {
		system("cls");
		p_Player->Render();
		cout << "1. 필드 2. 종료 : ";
		cin >> input;
		if (input == 1) {
			if (p_Field)
				p_Field->Update();
		}
		if (input == 2) {
			return;
		}
	}

	return;
}

void MainGame::Release()
{
	SAFE_DELETE(p_Player);
	SAFE_DELETE(p_Field);
}
