#pragma once
#include "Obj.h"

class Monster : public Obj
{ 
public:
	Monster() : Obj("",0,0) {};
	Monster(string name, int hp, int att) : Obj(name, hp, att) {};
	~Monster();

	void Initialize();
	void Update();
	void Release();

	//void Create(string name, int hp, int att);		// 생성자도 있지만, 혹시 몰라서 따로 생성 함수를 만듬
};

