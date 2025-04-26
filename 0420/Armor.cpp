#include "pch.h"
#include "Armor.h"

Armor::Armor(const std::string& part, int extraHp)
	: Item("", 0), E_Hp(extraHp)
{
	size_t idx = rand() % partName.size();
	ArmorPart = partName[idx];
	size_t pfx = rand() % prefix.size();
	name = prefix[pfx] + ArmorPart;
	E_Hp = HP_Check(name);
	price = Price_Check(name);
}

Armor::~Armor()
{
}

void Armor::Initialize()
{
}

void Armor::Update()
{
}

void Armor::Release()
{
}

int Armor::HP_Check(string prefix)
{
	int extraHp = 0;
	if (prefix.find("������ ") != string::npos) {
		return extraHp = rand() % 3 + 15;
	}
	else if (prefix.find("���� ���� ���� ") != string::npos) {
		return extraHp = rand() % 3 + 25;
	}
	else if (prefix.find("���� ") != string::npos) {
		return extraHp = rand() % 3 + 8;
	}
	else if (prefix.find("��� ������ ") != string::npos) {
		return extraHp = rand() % 3 + 3;
	}
	else {
		return 0;
	}
	return 0;
}

int Armor::Price_Check(string prefix)
{
	int price = 0;
	if (prefix.find("������ ") != string::npos) {
		return price = 13;
	}
	else if (prefix.find("���� ���� ���� ") != string::npos) {
		return price = 18;
	}
	else if (prefix.find("���� ") != string::npos) {
		return price = 5;
	}
	else if (prefix.find("��� ������ ") != string::npos) {
		return price = 1;
	}
	else {
		return 0;
	}
	return 0;
}

//int Armor::ShowStat() const
//{
//	return E_Hp;
//}

string Armor::getPartName() const
{
	return ArmorPart;
}

int Armor::getE_Hp() const
{
	return E_Hp;
}

inline Equipment Armor::getEquipSlot() const {
	if (ArmorPart == "����") return Equipment::Head;
	if (ArmorPart == "����") return Equipment::Chest;
	if (ArmorPart == "����") return Equipment::Legs;
	if (ArmorPart == "�尩") return Equipment::Gloves;
	if (ArmorPart == "�Ź�") return Equipment::Boots;
	if (ArmorPart == "����") return Equipment::Weapon;

	return Equipment::Head;
}
