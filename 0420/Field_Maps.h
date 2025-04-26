#pragma once
#include "Info.h"
#include "Mob.h"

class Field_Maps
{
	int array[3][3]{};
	
public:
	Field_Maps();
	~Field_Maps();

public:
	void Initialize();
	void Update(const Info& player);
	void Release();

public:
	int Move(int (*pArray)[3], int i, int j, int input, int mob_num, const Info& player) const;
};

