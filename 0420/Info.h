#pragma once
#include "pch.h"
#include "Equipment.h"

class Info {
	string name;
	int hp, att;

	map<Equipment, unique_ptr<Item>> equipment;
public:
	Info(const string& n = "", int h = 0, int a = 0);
	~Info();
public:
	void Initialize();
	void Update();
	void Release();

public:
	void print() const;

	string getName() const;
	int getHp() const;
	int getAtt() const;
	void takeDamage(int d);
	void setHp(int v);

	void equip(unique_ptr<Item> item);
	unique_ptr<Item> unequip(Equipment slot);

	void showEquipment() const;
};