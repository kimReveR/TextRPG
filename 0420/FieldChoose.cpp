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
	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷ� 7. �κ��丮 8. ���â : ";
	int level;
	cin >> level;

	return level;
}

void FieldChoose::Release()
{
}
