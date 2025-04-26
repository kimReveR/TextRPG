#include "pch.h"
#include "FieldChoose.h"
#include "Info.h"
#include "Inventory.h"

FieldChoose::FieldChoose()
{
}

FieldChoose::~FieldChoose()
{
}

void FieldChoose::Initialize()
{
}

int FieldChoose::Update(const Info& player)
{
	Inventory inven;
	system("cls");
	player.print();
	cout << "1. 초급 2. 중급 3. 고급 4. 뒤로 7. 인벤토리 8. 장비창 : ";
	int level;
	cin >> level;

	return level;
}

void FieldChoose::Release()
{
}
