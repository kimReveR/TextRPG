#pragma once
#include "pch.h"
#define SAFE_DELETE(p) if(p) { delete p; p=nullptr;}

typedef struct pInfo {
	std::string stdName;
	int iHp;
	int iAttack;
}INFO;