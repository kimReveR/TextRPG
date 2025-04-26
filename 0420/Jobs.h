#pragma once
#include "Info.h"
#include "Load.h"

class Jobs
{

public:
	Jobs();
	~Jobs();
public:
	void Initialize();
	void Update(Info& player);
	void Release();
};

