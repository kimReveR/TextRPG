#pragma once
#include "Player.h"
#include "Field.h"
#include "Store.h"

class MainGame
{
public:
	~MainGame() { Release(); }

	void Initialize();
	void Update();
	void Release();

private:
	Obj* pPlayer = nullptr;
	Field* pField = nullptr;
	Store* pStore = nullptr;
};

