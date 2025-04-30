#pragma once
#include "Obj.h"
class Monster :  public Obj
{
public:
	Monster() {};
	Monster(std::string n, int h, int a) : Obj(n, h, a, 0) {};
	~Monster() {};

	void Initialize();

	void Render() override;
};

