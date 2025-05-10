
#include "pch.h"
#include"Student_Add.h"
#include"Student_Erase.h"
#include"Student_Find.h"

int main()
{
    Student_Add add;
    Student_Erase erase;
    Student_Find find;

    int input;
    while (true) {
        system("cls");
        for (auto it = dent.begin(); it != dent.end(); it++) {
            it->Render();
        }
        cout << "1. 추가 2. 삭제 3. 검색 4. 종료 : ";
        cin >> input;

        switch (input) {
        case 1:             // 추가
            add.Update();
            break;
        case 2:             // 삭제
            erase.Update();
            break;
        case 3:             // 검색
            find.Update();
            break;
        case 4:             // 종료
            return 0;

        //case 7:         // 벡터 capacity와 size가 맞나 테스트 용 코드
        //    cout << dent.size() << "\t" << dent.capacity() << endl;
        //    system("pause");
        //    break;
        }
    }

    return 0;
}
