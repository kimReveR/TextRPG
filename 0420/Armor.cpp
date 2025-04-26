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
	if (prefix.find("쓸만한 ") != string::npos) {
		return extraHp = rand() % 3 + 15;
	}
	else if (prefix.find("거의 새것 같은 ") != string::npos) {
		return extraHp = rand() % 3 + 25;
	}
	else if (prefix.find("낡은 ") != string::npos) {
		return extraHp = rand() % 3 + 8;
	}
	else if (prefix.find("폐기 직전의 ") != string::npos) {
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
	if (prefix.find("쓸만한 ") != string::npos) {
		return price = 13;
	}
	else if (prefix.find("거의 새것 같은 ") != string::npos) {
		return price = 18;
	}
	else if (prefix.find("낡은 ") != string::npos) {
		return price = 5;
	}
	else if (prefix.find("폐기 직전의 ") != string::npos) {
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
	if (ArmorPart == "투구") return Equipment::Head;
	if (ArmorPart == "상의") return Equipment::Chest;
	if (ArmorPart == "하의") return Equipment::Legs;
	if (ArmorPart == "장갑") return Equipment::Gloves;
	if (ArmorPart == "신발") return Equipment::Boots;
	if (ArmorPart == "무기") return Equipment::Weapon;

	return Equipment::Head;
}
