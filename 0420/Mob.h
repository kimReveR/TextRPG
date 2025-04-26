#pragma once
#include "pch.h"
#include "Info.h"

class Mob {
	Info info;

public:
	void Create(int level);

	void print() const;
	int getHp() const;
	int getAtt() const;
	void takeDamage(int d);
};