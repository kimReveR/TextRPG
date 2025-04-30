#pragma once
#include "Item.h"
#include "Player.h"
class Store
{
public:
	Store();
	~Store();

	void Initialize();
	void Update();
	void Release();
	
	void setPlayer(Player* p) { pPlayer = p; }
	void Render(int i);

private:
	Obj* pItem[IT_END][IC_END];
	Obj* pPlayer = nullptr;
};

