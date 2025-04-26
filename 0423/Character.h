#pragma once
#include "pch.h"

class Character{
protected:
	string CName;
	int CHp;
	int CAtt;

public:
	enum JOBINDEX { WARRIOR = 1, MAGE, THIEF };

	Character();
	virtual ~Character() {};

	virtual void Render() const = 0;

	string getName() const { return CName; };
	int getHp() const { return CHp; };
	int getAtt() const { return CAtt; };
	string setName(string str) { return CName = str; };
	int setHp(int hp) { return CHp = hp; };
	int setAtt(int att) { return CAtt = att; };
};