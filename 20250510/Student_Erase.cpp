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
	cout << "몇 번째 학생의 데이터를 삭제하겠습니까? ";
	cin >> input;

	if (input > dent.size() || input < 1) { cout << "범위 넘음" << endl; system("pause"); return; }

	dent.erase(dent.begin() + input-1);

	cout << "삭제 완료" << endl;

	//cout << dent.size() << "\t" << dent.capacity() << endl;	// 테스트 코드
	dent.shrink_to_fit();			// 벡터의 capacity 맞추기
	system("pause");
}

void Student_Erase::Release()
{
}
