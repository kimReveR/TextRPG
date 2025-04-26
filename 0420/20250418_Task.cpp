#include "pch.h"
#include "MainGame.h"


int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	MainGame maingame;

	maingame.run();

	return 0;
}

