#include "pch.h"
#include "MainGame.h"

MainGame::MainGame()
{
	player = nullptr;
	field = nullptr;
	shop = nullptr;
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	if (!player) {
		player = new Player;
	}
	player->Update();
	if (!field) {
		field = new Field;
	}
	field->Initialize();
	field->SetPlayer(player);
	if (!shop) {
		shop = new Shop;
	}
	shop->Initialize();
}

void MainGame::Update()
{
	
	int input;
	while (true) {
		system("cls");
		player->Render();
		cout << "1. 필드 2. 상점 3. 종료";
		cin >> input;
		switch (input) {
		case 1:
			field->Update();
			break;
		case 2:
			shop->Update();
			break;
		case 3:
			return;
		}
	}
}

void MainGame::Release()
{
	delete player;
	delete field;
	delete shop;
}
