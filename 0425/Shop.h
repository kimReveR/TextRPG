#pragma once
#include "Item.h"

class Shop : public Item
{
	enum EQUIP { �ʱ� = 1, �߱�, ��� };

public:
	Shop() {};
	~Shop() {};

	void Initialize();
	void Release();
public:
	void Update() override;
	void Weapon();
	void Armor();
	bool Buy_Confirm(int buy);

private:
	Item items;
};

