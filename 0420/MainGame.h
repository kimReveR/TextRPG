#pragma once
#include"pch.h"
#include"Info.h"
#include "GameMenu.h"
#include "FieldChoose.h"
#include "Fight.h"

class GameMenu;			// 전방 선언
class FieldChoose;
class Fight;

class MainGame
{
public:
	MainGame();
	~MainGame();
	
public:
	void Initialize();
	void Update();
	void Release();

public:
	void ChooseJob();
	void showInfo();

public:
	void run();
	Info& getPlayerInfo() {
		return p_Info;
	}

private:
	Info p_Info;

	GameMenu* menu;
	FieldChoose* field;
	Fight* fight;
};

