#pragma once
#include "pch.h"

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}

typedef struct pInfo {
	string strName;
	int iHp;
	int iAtt;
};
