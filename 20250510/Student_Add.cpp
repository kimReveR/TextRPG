#include "pch.h"
#include "Student_Add.h"

void Student_Add::Initialize()
{
	//if (!info) {
	//	info = new INFO;
	//}
}

void Student_Add::Update()
{
	system("cls");
	int input;
	cout << "�߰��� �л� �� : ";
	cin >> input;

	string n;
	int k, m, e;

	for (int i = 0; i < input; i++) {
		cout << i + 1 << "��° �л� : " << endl;
		cout << "�̸� : ";
		cin >> n;
		cout << "���� : ";
		cin >> k;
		cout << "���� : ";
		cin >> m;
		cout << "���� : ";
		cin >> e;

		dent.push_back(student(n, k, m, e));
		system("cls");
	}
}

void Student_Add::Release()
{

}
