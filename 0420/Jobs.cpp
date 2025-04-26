#include "pch.h"
#include "Jobs.h"
#include "Inventory.h"
#include "Global.h"

Jobs::Jobs()
{
}

Jobs::~Jobs()
{
}

void Jobs::Initialize()
{
}

void Jobs::Update(Info& player)
{
	int job;
	cout << "직업 선택(1. 전사 2. 마법사 3. 도적 4. 불러오기) : ";
	cin >> job;
	Load load;

	switch (job) {
	case 1:
		player = Info("전사", 100, 10);
		break;
	case 2:
		player = Info("마법사", 100, 10);
		break;
	case 3:
		player = Info("도적", 100, 10);
		break;
	case 4:
		if (!load.Update("../sav.bin", player, g_inventory)) {
			cerr << "로드 실패" << endl;
		}
		break;
	default:
		cout << "종료" << endl;
		return;
	}
}

void Jobs::Release()
{
}
