#pragma once
#include "Item.h"
#include "Equipment.h"

class Armor : public Item
{
protected:
	string ArmorName;
	string ArmorPart;
	int E_Hp;

	vector<std::string> partName{ "����", "����", "����", "�尩", "�Ź�" };
	vector<std::string> prefix{ "������ ", "��� ������ ", "���� ���� ���� ", "���� " };

public:
	Armor(const std::string& part, int extraHp);
	~Armor();

public:
	void Initialize();
	void Update();
	void Release();

	ItemType getTypeId() const override {
		return ItemType::Armor;
	}

	int HP_Check(string prefix);
	int Price_Check(string prefix);
	//int ShowStat() const;

	string getPartName() const;
	int getE_Hp() const;

	Equipment getEquipSlot() const override;

};

