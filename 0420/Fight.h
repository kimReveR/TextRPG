#pragma once
#include "Mob.h"
#include "Info.h"

class Fight
{
	Mob mob;

public:
	Fight();
	~Fight();
public:
	void Initialize(const Info& player, int level);
	bool Update(Info& player);
	void Release();
};

