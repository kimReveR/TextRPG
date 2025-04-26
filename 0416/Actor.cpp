#include "Actor.h"

Actor::Actor(const string& name, int att, int hp, int exp, int money, int lvl) :
	Name(name), Att(att), Hp(hp), Exp(exp), Money(money), Lvl(lvl) {
	curr_Att = Att, curr_Hp = Hp, Crit = 0.5;
}

Actor Actor::Job_Select(int input, Actor player)
{
	Actor character("", 0, 0, 0, 0, 0); // 외부 변수 이름은 소문자로 변경해서 혼동 방지

	switch (input) {
	case 1:
		character = Actor("전사", 9, 120, 0, 0, 1);
		break;
	case 2:
		character = Actor("마법사", 12, 90, 0, 0, 1);
		break;
	case 3:
		character = Actor("돚거", 11, 105, 0, 0, 1);
		break;
	case 4:
		character = Load();
		break;
	default:
		character = Actor(); // 기본 생성자로 초기화
		break;
	}
	return character;
}

void Actor::info() const
{
	std::cout << "=====================================" << endl;
	std::cout << "이름: " << Name << "\n체력: " << curr_Hp << "\t공격력: " << curr_Att
		<< "\n레벨: " << Lvl << "\t경험치: " << Exp << "\t소지금: " << Money
		<< "\n다음 레벨업 까지: " << expTable[Lvl] - Exp << endl;
}

void Actor::mob_Info() const
{
	std::cout << "=====================================" << endl;
	std::cout << "이름: " << Name << "\n체력: " << Hp << "\t공격력: " << Att
		<< "\n레벨: " << Lvl << endl;
}

void Actor::Main_Game(Actor& player)
{
	int input;
	while (true) {
		std::system("cls");
		player.info();						// 직업 상태창
		std::cout << "1. 사냥터 2. 마을 3. 저장 4. 종료 : ";
		std::cin >> input;

		switch (input) {
		case 1:
			Field(player);
			break;
		case 2:
			Town(player);
			break;
		case 3:
			Save(player);
			break;
		case 4:
			return;
		default:
			break;
		}
	}
	return;
}

void Actor::Fight(Actor& player, Actor& mob)
{
	int crit_ratio = rand() % 10;
	if (crit_ratio == 7) {
		mob.Hp -= (player.curr_Att + (int)(player.curr_Att * player.Crit));

		std::cout << (player.curr_Att + (int)(player.curr_Att * player.Crit));
		if ((player.curr_Att + (int)(player.curr_Att * player.Crit)) > -2200000000) {
			std::cout << " SUDDEN DEATH!" << endl;
		}
		else {
			std::cout << " 크리티컬!" << endl;
		}
		player.curr_Hp -= mob.Att;
		std::system("pause");
	}
	else if (crit_ratio == 4) {
		mob.Hp -= player.curr_Att;
		player.curr_Hp -= (mob.Att + (int)(mob.Att * mob.Crit));
		std::cout << (mob.Att + (int)(mob.Att * mob.Crit)) << " 몹의 크리티컬!" << endl;
		std::system("pause");
	}
	else {
		mob.Hp -= player.curr_Att;
		player.curr_Hp -= mob.Att;
	}
}

void Actor::Level_Up(Actor& player)
{
	player.Att += 2;
	player.curr_Att += 2;							// 버프를 얻은 상태를 제외하고 공격력이 갱신 안될 수 도 있어서 갱신
	//if (player.curr_Att < player.Att) {				
	//	player.curr_Att = player.Att;
	//}
	std::cout << "기본 공격력이 2만큼 오름" << endl;
	player.Lvl += 1;
	player.Hp += 8;
	std::cout << "기본 체력이 8만큼 오름" << endl;
	//if (player.curr_Hp < player.Hp) {				// 레벨업을 했는데, 안올랐으면(왜 넣음? 이거 올리고 체력 만땅으로 올리잖아)
	//	player.curr_Hp = player.Hp;
	//}
	player.Exp = player.Exp - expTable[static_cast<std::vector<int, std::allocator<int>>::size_type>(player.Lvl) - 1];			// 경험치 한번 체크해봐야함
}

//void Actor::obtainItem(Item* item)
//{
//	inventory.addItem(item);
//}

//void Actor::showInventory() const
//{
//	inventory.display();
//	std::system("pause");
//}

void Actor::Save(const Actor& player)
{
	ofstream outFile("../Data/sav.bin", ios::out | ios::binary);
	if (!outFile.is_open()) {
		cerr << "세이브 오류" << endl;
		return;
	}
	// 이름 저장: 먼저 문자열 길이 저장 후, 문자열 데이터 저장
	size_t nameLength = player.Name.size();
	outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
	outFile.write(player.Name.c_str(), nameLength);

	// 정수 및 기타 멤버 저장
	outFile.write(reinterpret_cast<const char*>(&player.Att), sizeof(player.Att));
	outFile.write(reinterpret_cast<const char*>(&player.curr_Att), sizeof(player.curr_Att));
	outFile.write(reinterpret_cast<const char*>(&player.Hp), sizeof(player.Hp));
	outFile.write(reinterpret_cast<const char*>(&player.curr_Hp), sizeof(player.curr_Hp));
	outFile.write(reinterpret_cast<const char*>(&player.Exp), sizeof(player.Exp));
	outFile.write(reinterpret_cast<const char*>(&player.Money), sizeof(player.Money));
	outFile.write(reinterpret_cast<const char*>(&player.Lvl), sizeof(player.Lvl));

	std::cout << "저장 성공" << endl;
	outFile.close();
	std::system("pause");

	return;
}

Actor Actor::Load()
{
	ifstream inFile("../Data/sav.bin", ios::in | ios::binary);
	if (!inFile.is_open()) {
		cerr << "세이브 파일 오류" << endl;
		return Actor();
	}

	Actor actor;		// 기본 생성자를 통해 빈 객체 생성

	// 1. 이름 복원: 먼저 이름 길이를 읽고, 그 길이만큼 데이터 읽은 후 string에 대입
	size_t nameLength = 0;
	inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

	char* buffer = new char[nameLength + 1];
	inFile.read(buffer, nameLength);
	buffer[nameLength] = '\0';
	actor.Name = buffer;
	delete[] buffer;

	// 남은 멤버 복원
	inFile.read(reinterpret_cast<char*>(&actor.Att), sizeof(actor.Att));
	inFile.read(reinterpret_cast<char*>(&actor.curr_Att), sizeof(actor.curr_Att));
	inFile.read(reinterpret_cast<char*>(&actor.Hp), sizeof(actor.Hp));
	inFile.read(reinterpret_cast<char*>(&actor.curr_Hp), sizeof(actor.curr_Hp));
	inFile.read(reinterpret_cast<char*>(&actor.Exp), sizeof(actor.Exp));
	inFile.read(reinterpret_cast<char*>(&actor.Money), sizeof(actor.Money));
	inFile.read(reinterpret_cast<char*>(&actor.Lvl), sizeof(actor.Lvl));

	inFile.close();
	return actor;
}

void Actor::Town(Actor& player)
{
	int input = 0;
	while (true) {
		std::system("cls");
		player.info();

		std::cout << "회복비용 : 15원" << endl;
		std::cout << "1. 회복 2. 전 단계 : ";
		std::cin >> input;

		switch (input) {
		case 1:									// 회복
			if (player.Money == 0 || player.Money < 15) {
				std::cout << "거지쉑" << endl;
				std::cout << "쫒겨났다" << endl;
				std::system("pause");
				return;
			}
			if (player.curr_Hp <= player.Hp) {
				player.curr_Hp = player.Hp;
				std::cout << "15원 으로 회복" << endl;
				player.Money -= 15;
				std::system("pause");
			}

			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

Actor::~Actor()
{

}


void Actor::Field(Actor& player)
{
	int input = 0;
	while (true) {
		std::system("cls");
		player.info();

		std::cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		std::cin >> input;
		//mobs = Monster(input);			// 원래 케이스에서 몬스터 생성을 했는데, 그냥 여기서 체크해야 필드 만들 때 몬스터 정보를 쉽게 불러올 수 있다.

		switch (input) {
		case 1:
		{
			Actor mobs("초급", 3, 30, rand() % 12 + 5, rand() % 15 + 3, rand() % 2 + 1);
			Field_Choose(player, mobs);
			break;
		}
		case 2:
		{
			Actor mobs("중급", 6, 60, rand() % 24 + 10, rand() % 30 + 7, rand() % 4 + 2);
			Field_Choose(player, mobs);
			break;
		}
		case 3:
		{
			Actor mobs("고급", 9, 90, rand() % 36 + 15, rand() % 45 + 12, rand() % 6 + 4);
			Field_Choose(player, mobs);
			break;
		}
		case 4:
			return;
		default:
			break;
		}
	}
}

void Actor::Field_Choose(Actor& player, Actor& mob)
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
		std::system("cls");
		for (int i = 0; i < 3; i++) {				// 맵 출력
			for (int j = 0; j < 3; j++) {
				std::cout << array[i][j] << '\t';
			}
			std::cout << endl;
		}
		int input = 0;
		int zero_i = 0, zero_j = 0;
		player.info();
		std::cout << "2,4,6,8로 이동, 입력 : ";
		std::cin >> input;

		for (int i = 0; i < 3; i++) {		//0의 현재 좌표 얻기
			for (int j = 0; j < 3; j++) {
				if (array[i][j] == 0) {
					zero_i = i;
					zero_j = j;
				}
			}
		}

		int exit = Move(pArray, zero_i, zero_j, input, mob_num, player, mob);

		if (input == 9) {
			std::cout << "사냥 종료" << endl;
			std::system("pause");
			return;
		}
		if (exit == 99) {
			std::cout << "사냥터 선택지로 돌아갑니다." << endl;
			std::system("pause");
			return;
		}
	}
}

int Actor::Move(int(*pArray)[3], int i, int j, int input, int mob_Num, Actor& player, Actor& mob)
{
	switch (input) {
	case 2:
		if (i + 1 > 2) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i + 1][j] == mob_Num) {
			Battle(player, mob);
			return 99;
		}
		swap(pArray[i][j], pArray[i + 1][j]);
		break;
	case 4:
		if (j - 1 < 0) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i][j - 1] == mob_Num) {
			Battle(player, mob);
			return 99;
		}
		swap(pArray[i][j], pArray[i][j - 1]);
		break;
	case 6:
		if (j + 1 > 2) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i][j + 1] == mob_Num) {
			Battle(player, mob);
			return 99;
		}
		swap(pArray[i][j], pArray[i][j + 1]);
		break;
	case 8:
		if (i - 1 < 0) {	// 필드 너머 움직임은 불가
			break;
		}
		if (pArray[i - 1][j] == mob_Num) {
			Battle(player, mob);
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

Actor Actor::Battle(Actor& player, Actor& mob)
{
	int input = 0;

	std::cout << "야생의 몬스터 " << mob.Name << "이 나타났다." << endl;		// 인카운터 메세지
	std::system("pause");
	while (true) {

		std::system("cls");
		player.info();
		mob.mob_Info();

		std::cout << "1. 공격 2. 도망 : ";
		std::cin >> input;

		/*int itemdrop = rand() % 5;*/
		switch (input) {
		case 1:
			Fight(player, mob);
			if (mob.Hp <= 0 && player.curr_Hp > 0) {
				std::cout << "승리" << endl;
				player.Exp += mob.Exp;
				std::cout << "경험치를 " << mob.Exp << "만큼 획득 했습니다." << endl;
				if (player.Exp > expTable[player.Lvl]) {
					std::cout << "레벨 업" << endl;
					Level_Up(player);

					player.curr_Hp = player.Hp;				// 체력회복 --버프받으면 다르게 넣을 수도 있음--
				}// 경험치 넘으면 레벨업
				player.Money += mob.Money;
				std::cout << "돈을 " << mob.Money << "만큼 획득 했습니다." << endl;
				/*if (itemdrop == 2) {*/
				//Armor* droppedArmor = new Armor("어떤 부위", 10, 1.0);
				//obtainItem(droppedArmor);
				//std::cout << droppedArmor->getName() << "획득" << endl;
				//}
				std::system("pause");
				return player;
			}
			else if (player.curr_Hp <= 0) {
				std::cout << "패배" << endl;
				player.curr_Hp = player.Hp;			// 초기값만큼 회복
				player.Exp = (int)(player.Exp * 0.9);		// 10퍼센트의 경험치를 잃음
				std::cout << "경험치 10% 감소" << endl;
				std::system("pause");
				return player;
			}

			if (player.curr_Hp <= 0 && mob.Hp <= 0) {
				std::cout << "무승부" << endl;
				player.curr_Hp = player.Hp;			// 초기값만큼 회복
				player.Exp = (int)(player.Exp * 0.9);		// 10퍼센트의 경험치를 잃음
				std::cout << "경험치 10% 감소" << endl;
				std::system("pause");
				return player;
			}
			break;
		case 2:
			return player;
		default:
			break;
		}
	}
}
