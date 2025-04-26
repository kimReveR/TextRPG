#pragma once
#include "Info.h"
#include "Inventory.h"
class Load
{
public:
	Load();
	~Load();
public:
	void Initialize();
	bool Update(const string& path,
		Info& player,
		Inventory& inv);
	void Release();
};

