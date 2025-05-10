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
	cout << "추가할 학생 수 : ";
	cin >> input;

	string n;
	int k, m, e;

	for (int i = 0; i < input; i++) {
		cout << i + 1 << "번째 학생 : " << endl;
		cout << "이름 : ";
		cin >> n;
		cout << "국어 : ";
		cin >> k;
		cout << "수학 : ";
		cin >> m;
		cout << "영어 : ";
		cin >> e;

		dent.push_back(student(n, k, m, e));
		system("cls");
	}
}

void Student_Add::Release()
{

}
