#include "pch.h"
#include "Student_Erase.h"

void Student_Erase::Initialize()
{
	//if (!info) {
	//	info = new INFO;
	//}
}

void Student_Erase::Update()
{
	system("cls");
	int input;
	cout << "�� ��° �л��� �����͸� �����ϰڽ��ϱ�? ";
	cin >> input;

	if (input > dent.size() || input < 1) { cout << "���� ����" << endl; system("pause"); return; }

	dent.erase(dent.begin() + input-1);

	cout << "���� �Ϸ�" << endl;

	//cout << dent.size() << "\t" << dent.capacity() << endl;	// �׽�Ʈ �ڵ�
	dent.shrink_to_fit();			// ������ capacity ���߱�
	system("pause");
}

void Student_Erase::Release()
{
}
