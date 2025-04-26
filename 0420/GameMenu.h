#pragma once
#include "pch.h"
#include "Info.h"

class GameMenu {

public:
	GameMenu();
	~GameMenu();
public:
	void Initialize();
	void Update(const Info& player);
	void Release();
};