#include "pch.h"
#include "Student_Find.h"

void Student_Find::Initialize()
{
	//if (!info) {
	//	info = new INFO;
	//}
}

void Student_Find::Update()
{
	system("cls");
	string input;
	cout << "ã�� �л��� �̸� : ";
	cin >> input;			// �̸� ���̿� ���Ⱑ �� �л���

	//vector<INFO>::iterator it = dent.begin();

	for (auto it = dent.begin(); it != dent.end(); it++) {
		if (it->name == input) {
			it->Render();
			system("pause");
			return;
		}
	}
	cout << "�л� ����" << endl;
	system("pause");
}

void Student_Find::Release()
{
}
