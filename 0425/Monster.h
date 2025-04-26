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

	//void Create(string name, int hp, int att);		// �����ڵ� ������, Ȥ�� ���� ���� ���� �Լ��� ����
};

