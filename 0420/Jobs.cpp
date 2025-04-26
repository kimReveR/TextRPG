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
	cout << "���� ����(1. ���� 2. ������ 3. ���� 4. �ҷ�����) : ";
	cin >> job;
	Load load;

	switch (job) {
	case 1:
		player = Info("����", 100, 10);
		break;
	case 2:
		player = Info("������", 100, 10);
		break;
	case 3:
		player = Info("����", 100, 10);
		break;
	case 4:
		if (!load.Update("../sav.bin", player, g_inventory)) {
			cerr << "�ε� ����" << endl;
		}
		break;
	default:
		cout << "����" << endl;
		return;
	}
}

void Jobs::Release()
{
}
