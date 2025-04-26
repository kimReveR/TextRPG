#pragma once
#include "Equipment.h"

enum class ItemType : int {
	Armor = 1,
	// ... 나중에 Potion, Weapon 등 추가
};

class Item
{
protected:
	string name;
	int price;
public:
	Item(const string&name, int price);
	~Item();
public:
	void Initialize();
	void Update();
	void Release();

	virtual ItemType getTypeId() const = 0;
	virtual Equipment getEquipSlot() const = 0;

	string getName() const;
	void setName(string n);
	int getPrice() const;
	void setPrice(int p);
};

