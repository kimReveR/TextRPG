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
	cout << "찾을 학생의 이름 : ";
	cin >> input;			// 이름 사이에 띄어쓰기가 들어간 학생용

	//vector<INFO>::iterator it = dent.begin();

	for (auto it = dent.begin(); it != dent.end(); it++) {
		if (it->name == input) {
			it->Render();
			system("pause");
			return;
		}
	}
	cout << "학생 없음" << endl;
	system("pause");
}

void Student_Find::Release()
{
}
