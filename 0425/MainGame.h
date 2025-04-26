#pragma once
#include "Player.h"
#include "Field.h"
#include "Shop.h"
class MainGame
{
public:
	MainGame();
	~MainGame();

	void Initialize();
	void Update();
	void Release();

private:
	Obj* player;
	Field* field;
	Obj* shop;
};

