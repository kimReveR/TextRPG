#pragma once
#include "Obj.h"

class Item : public Obj
{
public:
	Item() {};
	Item(std::string n, int h, int a, int money) : Obj(n, h, a, money) {};
	~Item() {};

	void Initialize();

	void Render() override;

private:

};

