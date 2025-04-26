#pragma once
#ifndef ACTOR_H
#define ACTOR_H


#include "TextRPG.h"
//#include "Inventory.h"

typedef class Actor {
protected:
	string Name;
	int Att;					// �⺻ ���ݷ�(������ ���� ����)
	int curr_Att;				// ���� ���ݷ�(�����, ����, ��� ���� ����,����)
	int Hp;						// �⺻ ü��(��Ȱ�� ���� �⺻ ü��, ������ ���� ����)
	int curr_Hp;				// ���� ü��(�����, ����, ��� ���� ����, ����)
	int Exp;					// ����ġ
	int Money;					// ������
	int Lvl;					// ����(���µ� ���ϰ� �ұ� ������)
	double Crit;
	//Inventory inventory;

	vector<int> expTable = { 0, 100, 250, 476, 849, 1375, 1895, 2250, 2769, 3250 };

public:
	Actor() : Name(""), Att(0), Hp(0), Exp(0), Money(0), Lvl(0) { curr_Att = 0, curr_Hp = 0; Crit = 0.2; };
	Actor(const string& name, int att, int hp, int exp, int money, int lvl);
	//Actor(const Actor&) = delete;
	//Actor& operator=(const Actor&) = delete;

	Actor Job_Select(int input, Actor player);

	void info() const;
	void mob_Info() const;

	void Main_Game(Actor& player);

	void Field(Actor& player);
	void Field_Choose(Actor& player, Actor& mob);

	int Move(int (*pArray)[3], int i, int j, int input, int mob_Num, Actor& player, Actor& mob);
	Actor Battle(Actor& player, Actor& mob);
	void Fight(Actor& player, Actor& mob);
	void Level_Up(Actor& player);

	//void obtainItem(Item* item);
	//void showInventory() const;

	void Save(const Actor& player);
	Actor Load();

	void Town(Actor& player);

	

	virtual ~Actor();

}OBJ2;


#endif // !ACTOR_H