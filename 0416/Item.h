#pragma once
#ifndef ITEM_H
#define ITEM_H

#include "TextRPG.h"

class Item {
protected:
	std::string Name;		// 아이템 이름
	int Price;				// 아이템 가격

public:
	Item(const std::string& name, int price) : Name(name), Price(price) {};
	string getName() const { return Name; };
	~Item() {}
};


class Armor : public Item{	// Item 상속하는게 맞나?
private:
	std::string ArmorName;		// 장비 이름
	std::string ArmorPart;		// 장비 부위
	int E_Hp;					// 추가 체력
	double Number;

	vector<std::string> partName{ "투구", "상의", "하의", "장갑", "신발" };
	vector<std::string> prefix{ "쓸만한 ", "폐기 직전의 ", "거의 새것 같은 ", "낡은 " };

public:
	/*Armor() : Item("", 0), ArmorPart(""), E_Hp(0), Number(0) {};*/
	Armor(const std::string& part, int extraHp, double number) :
		Item("", 0), ArmorPart(part), E_Hp(extraHp), Number(number)
	{
		int R_Num = rand() % 5;
		ArmorPart = partName[R_Num];
		int R_Num2 = rand() % 4;
		Name = prefix[R_Num2] + partName[R_Num];
		E_Hp = HP_Check(Name);
		Price = Price_Check(Name);
		Number = rand() % 1235851 + 1;
		ArmorName = Name;
	};

	int HP_Check(std::string prefix);
	int Price_Check(std::string prefix);

	~Armor();
};
#endif