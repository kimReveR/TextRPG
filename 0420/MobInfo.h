#pragma once
#include "pch.h"
class MobInfo
{
private:
	string Mob_Name;
	int Hp;
	int Att;
public:
	MobInfo() { Hp = 0, Att = 0; }
	MobInfo(const string& mobname, int hp, int att) : Mob_Name(mobname), Hp(hp), Att(att) {}
	~MobInfo() {}

public:
	void Initialize() {};
	void Update() {};
	void Release() {};

public:
	string getName();
	int getHp() const;
	int getAtt() const;
	void Info();
	
	void takeDamage(int dmg);
};

