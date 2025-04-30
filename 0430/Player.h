#pragma once
#include "Obj.h"
class Player :  public Obj
{
public:
	Player() {};
	Player(std::string n, int h, int a, int money) : Obj(n, h, a, money) {};
	~Player() {};

	void Initialize();
	void Update();
	void Release();

	void Render() override;
};

