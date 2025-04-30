#pragma once
#include "Define.h"

class Obj
{
public:
	Obj() {};
	Obj(std::string n, int h, int a, int money) : pInfo(n, h, a, money) {};
	virtual ~Obj() {};

	virtual void Render() = 0;
	virtual int SetHp(int i) { return pInfo.iHp = i; };
	virtual int getHp() { return pInfo.iHp; }
	virtual int getAtt() { return pInfo.iAtt; }

	virtual void setDmg(int i) { pInfo.iHp -= i; }

protected:
	INFO pInfo;
};

