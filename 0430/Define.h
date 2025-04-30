#pragma once
#include "pch.h"
#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}

enum ITEMTYPE { IT_WEAPON, IT_ARMOR, IT_END };
enum ITEMCLASS { BEGGINER, RARE, UNIQUE, IC_END };

typedef struct pInfo {
	std::string strname;
	int iHp;
	int iAtt;
	int iMoney;

	pInfo() : iHp(0), iAtt(0), iMoney(0) {};
	pInfo(std::string n, int h, int a, int money) : strname(n), iHp(h), iAtt(a), iMoney(money) {};
}INFO;