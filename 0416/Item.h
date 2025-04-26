#pragma once
#ifndef ITEM_H
#define ITEM_H

#include "TextRPG.h"

class Item {
protected:
	std::string Name;		// ������ �̸�
	int Price;				// ������ ����

public:
	Item(const std::string& name, int price) : Name(name), Price(price) {};
	string getName() const { return Name; };
	~Item() {}
};


class Armor : public Item{	// Item ����ϴ°� �³�?
private:
	std::string ArmorName;		// ��� �̸�
	std::string ArmorPart;		// ��� ����
	int E_Hp;					// �߰� ü��
	double Number;

	vector<std::string> partName{ "����", "����", "����", "�尩", "�Ź�" };
	vector<std::string> prefix{ "������ ", "��� ������ ", "���� ���� ���� ", "���� " };

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