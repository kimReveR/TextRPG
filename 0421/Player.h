#pragma once
#include "Define.h"
class Player
{
private:
	INFO m_tInfo;
public:
	Player();
	~Player();

public:
	void Initialize();
	void Update();
	void Release();

	void Render();
	void Battle(int i);
	INFO GetInfo();
	void SetHp(int i);
};

