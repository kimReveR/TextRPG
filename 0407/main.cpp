#include "main.h"


OBJ* Job_Select();
OBJ* Monster(int input);
OBJ* Load(OBJ* pObjs);

void Create(OBJ** ppObj, const char* pName, int Attack, int Hp, int Exp, int Money, int Lvl);

void Main_Game(OBJ* obj);

void Job_Info(OBJ* obj);
void Mob_Info(OBJ* mob);

void Field(OBJ* _obj);
void Field_Choose(OBJ* pObjs, OBJ* pMobs);

void Town(OBJ* _obj);

int Move(int (*pArray)[3], int i, int j, int input, int mob_Num, OBJ* pJobs, OBJ* pMobs);
void Battle(OBJ* __obj, OBJ* _mob);
void Fight(OBJ* _pObj, OBJ* _pMob);
void Level_Up(OBJ* pobj);

void Save(OBJ* _obj);

vector<int> expTable = { 0, 100, 250, 476, 849, 1375, 1895, 2250, 2769, 3250 };

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(unsigned(time(NULL)));
	OBJ* objects = Job_Select();

	if (objects == nullptr) {
		return 0;
	}

	Main_Game(objects);

	if (objects != nullptr) {
		delete objects;
		objects = nullptr;
	}

	return 0;
}

// 직업 생성
OBJ* Job_Select()
{
	OBJ* obj = nullptr;
	int input = 0;
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 불러오기) : ";
	cin >> input;

	switch (input) {
	case 1:
		Create(&obj, "전사", 9, 120, 0, 0, 1);
		break;
	case 2:
		Create(&obj, "마법사", 12, 90, 0, 0, 1);
		break;
	case 3:
		Create(&obj, "도적", 11, 100, 0, 0, 1);
		break;
	case 4:
		obj = Load(obj);
		break;
	default:
		Create(&obj, "", 0, 0, 0, 0, 0);
		return obj;
	}


	return obj;
}

void Create(OBJ** ppObj, const char* pName, int Attack, int Hp, int Exp, int Money, int Lvl)		// 직업, 몬스터 생성
{
	*ppObj = new OBJ;

	strcpy_s((*ppObj)->Name, sizeof((*ppObj)->Name), pName);
	(*ppObj)->Att = Attack;
	(*ppObj)->Hp = Hp;
	(*ppObj)->Exp = Exp;
	(*ppObj)->Money = Money;
	(*ppObj)->Lvl = Lvl;

	(*ppObj)->curr_Att = (*ppObj)->Att;
	(*ppObj)->curr_Hp = (*ppObj)->Hp;
}

void Main_Game(OBJ* obj)
{
	int input;
	while (true) {
		system("cls");
		Job_Info(obj);						// 직업 상태창

		cout << "1. 사냥터 2. 마을 3. 저장 4. 종료 : ";
		cin >> input;

		switch (input) {
		case 1:
			Field(obj);
			break;
		case 2:
			Town(obj);
			break;
		case 3:
			Save(obj);
			break;
		case 4:
			return;
		default:
			break;
		}
	}
	return;
}

// 캐릭터 상태창과 몬스터 상태창

void Job_Info(OBJ* obj)
{
	cout << "=====================================" << endl;
	cout << "이름: " << obj->Name << "\n체력: " << obj->curr_Hp << "\t공격력: " << obj->curr_Att
		<< "\n레벨: " << obj->Lvl << "\t경험치: " << obj->Exp << "\t소지금: " << obj->Money 
		<< "\n다음 레벨업 까지: " << expTable[obj->Lvl] - obj->Exp<<endl;
}

void Mob_Info(OBJ* mob)
{
	cout << "=====================================" << endl;
	cout << "이름: " << mob->Name << "\n체력: " << mob->Hp << "\t공격력: " << mob->Att
		<< "\n레벨: " << mob->Lvl << endl;
}

// 사냥터 선택
void Field(OBJ* _obj)
{
	int input = 0;
	while (true) {
		OBJ* mobs = nullptr;
		system("cls");
		Job_Info(_obj);

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> input;
		mobs = Monster(input);			// 원래 케이스에서 몬스터 생성을 했는데, 그냥 여기서 체크해야 필드 만들 때 몬스터 정보를 쉽게 불러올 수 있다.

		switch (input) {
		case 1:
			Field_Choose(_obj, mobs);
			delete mobs;
			mobs = nullptr;
			break;
		case 2:
			Field_Choose(_obj, mobs);
			delete mobs;
			mobs = nullptr;
			break;
		case 3:
			Field_Choose(_obj, mobs);
			delete mobs;
			mobs = nullptr;
			break;
		case 4:
			delete mobs;
			mobs = nullptr;
			return;
		default:
			delete mobs;
			mobs = nullptr;
			break;
		}
	}
}

void Field_Choose(OBJ* pObjs, OBJ* pMobs)
{
	int array[3][3]{};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			array[i][j] = i * 3 + j;			// 3*3필드의 값 넣기
		}
	}

	for (int k = 0; k < 50; k++) {					// 몬스터 위치가 랜덤으로 하려고 섞음
		int dst = rand() % 3;
		int src = rand() % 3;

		swap(array[dst][src], array[src][dst]);
	}

	int mob_num = rand() % 8 + 1;		// 0 제외 1~8까지의 수 중 랜덤 한개를 고름, 이 수가 몬스터 위치

	int (*pArray)[3] = array;
	while (true) {
		system("cls");
		for (int i = 0; i < 3; i++) {				// 맵 출력
			for (int j = 0; j < 3; j++) {
				cout << array[i][j] << '\t';
			}
			cout << endl;
		}
		int input = 0;
		int zero_i = 0, zero_j = 0;
		Job_Info(pObjs);
		cout << "2,4,6,8로 이동, 입력 : ";
		cin >> input;

		for (int i = 0; i < 3; i++) {		//0의 현재 좌표 얻기
			for (int j = 0; j < 3; j++) {
				if (array[i][j] == 0) {
					zero_i = i;
					zero_j = j;
				}
			}
		}

		int exit = Move(pArray, zero_i, zero_j, input, mob_num, pObjs, pMobs);

		if (input == 9) {
			cout << "사냥 종료" << endl;
			system("pause");
			return;
		}
		if (exit == 99) {
			cout << "사냥터 선택지로 돌아갑니다." << endl;
			system("pause");
			return;
		}
	}
}

void Town(OBJ* _obj)
{
	int input = 0;
	while (true) {
		system("cls");
		Job_Info(_obj);

		cout << "1. 회복 2. 전 단계 : ";
		cin >> input;

		switch (input) {
		case 1:									// 회복
			if (_obj->curr_Hp <= _obj->Hp) {
				_obj->curr_Hp = _obj->Hp;
				cout << "15원 으로 회복" << endl;
				_obj->Money -= 15;
				system("pause");
			}
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

int Move(int(*pArray)[3], int i, int j, int input, int mob_Num, OBJ* pJobs, OBJ* pMobs)
{
	switch (input) {
	case 2:
		if (i + 1 > 2) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i + 1][j] == mob_Num) {
			Battle(pJobs, pMobs);
			return 99;
		}
		swap(pArray[i][j], pArray[i + 1][j]);
		break;
	case 4:
		if (j - 1 < 0) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i][j - 1] == mob_Num) {
			Battle(pJobs, pMobs);
			return 99;
		}
		swap(pArray[i][j], pArray[i][j - 1]);
		break;
	case 6:
		if (j + 1 > 2) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i][j + 1] == mob_Num) {
			Battle(pJobs, pMobs);
			return 99;
		}
		swap(pArray[i][j], pArray[i][j + 1]);
		break;
	case 8:
		if (i - 1 < 0) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i - 1][j] == mob_Num) {
			Battle(pJobs, pMobs);
			return 99;
		}
		swap(pArray[i][j], pArray[i - 1][j]);
		break;
	case 9:
		return 1;
	default:
		return 8;
	}
	return 0;
}

// 배틀
void Battle(OBJ* __obj, OBJ* _mob)
{
	int input = 0;

	cout << "야생의 몬스터 " << _mob->Name << "이 나타났다." << endl;		// 인카운터 메세지
	system("pause");
	while (true) {
		
		system("cls");
		Job_Info(__obj);
		Mob_Info(_mob);

		cout << "1. 공격 2. 도망 : ";
		cin >> input;

		switch (input) {
		case 1:
			Fight(__obj, _mob);
			if (_mob->Hp <= 0 && __obj->curr_Hp > 0) {
				cout << "승리" << endl;
				__obj->Exp += _mob->Exp;
				cout << "경험치를 " << _mob->Exp << "만큼 획득 했습니다." << endl;
				if (__obj->Exp > expTable[__obj->Lvl]) {
					cout << "레벨 업" << endl;
					Level_Up(__obj);

					__obj->curr_Hp = __obj->Hp;				// 체력회복 --버프받으면 다르게 넣을 수도 있음--
				}// 경험치 넘으면 레벨업
				__obj->Money += _mob->Money;
				cout << "돈을 " << _mob->Money << "만큼 획득 했습니다." << endl;
				//system("pause");
				return;
			}
			else if (__obj->curr_Hp <= 0) {
				cout << "패배" << endl;
				__obj->curr_Hp = __obj->Hp;			// 초기값만큼 회복
				__obj->Exp = __obj->Exp * 0.9;		// 10퍼센트의 경험치를 잃음
				cout << "경험치 10% 감소" << endl;
				system("pause");
				return;
			}

			if (__obj->curr_Hp <= 0 && _mob->Hp <= 0) {
				cout << "무승부" << endl;
				__obj->curr_Hp = __obj->Hp;			// 초기값만큼 회복
				__obj->Exp = __obj->Exp * 0.9;		// 10퍼센트의 경험치를 잃음
				cout << "경험치 10% 감소" << endl;
				system("pause");
				return;
			}
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

//기본 공격 공식
void Fight(OBJ* _pObj, OBJ* _pMob)
{
	_pMob->Hp = _pMob->Hp - _pObj->curr_Att;
	_pObj->curr_Hp = _pObj->curr_Hp - _pMob->Att;
}

void Level_Up(OBJ* pobj)
{
	pobj->Att += 2;	
	pobj->curr_Att += 2;							// 버프를 얻은 상태를 제외하고 공격력이 갱신 안될 수 도 있어서 갱신
	//if (pobj->curr_Att < pobj->Att) {				
	//	pobj->curr_Att = pobj->Att;
	//}
	cout << "기본 공격력이 2만큼 오름" << endl;
	pobj->Lvl += 1;
	pobj->Hp += 8;
	cout << "기본 체력이 8만큼 오름" << endl;
	//if (pobj->curr_Hp < pobj->Hp) {				// 레벨업을 했는데, 안올랐으면(왜 넣음? 이거 올리고 체력 만땅으로 올리잖아)
	//	pobj->curr_Hp = pobj->Hp;
	//}
	pobj->Exp = pobj->Exp - expTable[static_cast<std::vector<int, std::allocator<int>>::size_type>(pobj->Lvl) - 1];			// 경험치 한번 체크해봐야함
}

// 진행사항 저장
void Save(OBJ* _obj)
{
	ofstream outFile("../Data/save.txt", ios::out | ios::binary);
	if (!outFile.is_open()) {										// 세이브 파일관련 에러
		cerr << "세이브 파일을 불러올 수 없습니다." << endl;
		return;
	}
	outFile.write(reinterpret_cast<char*>(_obj), sizeof(OBJ));		// fwrite와 동일하게 만들 수 있음
	//reinterpret_cast는 임의의 포인터 타입끼리 변환을 허용하는 캐스트 연산자
	//	출처 : https://blockdmask.tistory.com/242 [가면 뒤의 기록:티스토리]
	cout << "저장 성공" << endl;
	outFile.close();
	system("pause");

#pragma region c언어로 세이브
	/*FILE* file = nullptr;
	OBJ* save = _obj;

	errno_t err = fopen_s(&file, "../Data/save.txt", "wb");

	if (err == 0) {
		fwrite(save, sizeof(*save), 1, file);
		cout << "성공" << endl;
		fclose(file);
	}
	else {
		cout << "실패" << endl;
	}*/
#pragma endregion	

	return;
}

// 몬스터 만들어지는 코드
OBJ* Monster(int input) {
	OBJ* mobs = nullptr;

	switch (input) {
	case 1:
		Create(&mobs, "초급", 3, 30, rand() % 12 + 5, rand() % 15 + 3, rand() % 2 + 1);
		break;
	case 2:
		Create(&mobs, "중급", 6, 60, rand() % 24 + 10, rand() % 30 + 7, rand() % 4 + 2);
		break;
	case 3:
		Create(&mobs, "고급", 9, 90, rand() % 36 + 15, rand() % 45 + 12, rand() % 6 + 4);
		break;
	case 4:
		return mobs;
	default:
		break;
	}

	return mobs;
}

OBJ* Load(OBJ* pObjs)
{
	if (pObjs == nullptr) {						// nulllptr로 불러왔을 때 새로 선언
		pObjs = new OBJ;
	}

	ifstream inFile("../Data/save.txt", ios::in | ios::binary);
	if (!inFile.is_open()) {
		cerr << "세이브 파일 없음" << endl;
		return pObjs;
	}

	inFile.read(reinterpret_cast<char*>(pObjs), sizeof(OBJ));		// fread와 동일하게 만들 수 있음

	inFile.close();
#pragma region c언어로 로드
	/*FILE* pFile = nullptr;
	errno_t err = fopen_s(&pFile, "../Data/save.txt", "rb");

	if (err == 0) {
		fread(pObjs, sizeof(*pObjs), 1, pFile);
		fclose(pFile);
	}*/
#pragma endregion
	// Create함수로 만들었더니, 메모리 누수가 남
	OBJ* newObjs = new OBJ;						// 여기서 그대로 넣으면 메모리 누수 나서 새로운 구조체를 만들어서, 기존의 것은 파괴해서 누수 해결
	strcpy_s(newObjs->Name, sizeof(newObjs->Name), pObjs->Name);
	newObjs->Att = pObjs->Att;
	newObjs->curr_Att = pObjs->curr_Att;
	newObjs->Hp = pObjs->Hp;
	newObjs->curr_Hp = pObjs->curr_Hp;
	newObjs->Exp = pObjs->Exp;
	newObjs->Money = pObjs->Money;
	newObjs->Lvl = pObjs->Lvl;

	delete pObjs;

	return newObjs;
}
