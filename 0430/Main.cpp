#include "pch.h"
#include "MainGame.h"

int main()
{
	_CrtDumpMemoryLeaks();
	MainGame mg;
	mg.Initialize();
	mg.Update();

	return 0;
}
