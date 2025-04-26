#include "Actor.h"

Actor::Actor(const string& name, int att, int hp, int exp, int money, int lvl) :
	Name(name), Att(att), Hp(hp), Exp(exp), Money(money), Lvl(lvl) {
	curr_Att = Att, curr_Hp = Hp, Crit = 0.5;
}

Actor Actor::Job_Select(int input, Actor player)
{
	Actor character("", 0, 0, 0, 0, 0); // �ܺ� ���� �̸��� �ҹ��ڷ� �����ؼ� ȥ�� ����

	switch (input) {
	case 1:
		character = Actor("����", 9, 120, 0, 0, 1);
		break;
	case 2:
		character = Actor("������", 12, 90, 0, 0, 1);
		break;
	case 3:
		character = Actor("����", 11, 105, 0, 0, 1);
		break;
	case 4:
		character = Load();
		break;
	default:
		character = Actor(); // �⺻ �����ڷ� �ʱ�ȭ
		break;
	}
	return character;
}

void Actor::info() const
{
	std::cout << "=====================================" << endl;
	std::cout << "�̸�: " << Name << "\nü��: " << curr_Hp << "\t���ݷ�: " << curr_Att
		<< "\n����: " << Lvl << "\t����ġ: " << Exp << "\t������: " << Money
		<< "\n���� ������ ����: " << expTable[Lvl] - Exp << endl;
}

void Actor::mob_Info() const
{
	std::cout << "=====================================" << endl;
	std::cout << "�̸�: " << Name << "\nü��: " << Hp << "\t���ݷ�: " << Att
		<< "\n����: " << Lvl << endl;
}

void Actor::Main_Game(Actor& player)
{
	int input;
	while (true) {
		std::system("cls");
		player.info();						// ���� ����â
		std::cout << "1. ����� 2. ���� 3. ���� 4. ���� : ";
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
			std::cout << " ũ��Ƽ��!" << endl;
		}
		player.curr_Hp -= mob.Att;
		std::system("pause");
	}
	else if (crit_ratio == 4) {
		mob.Hp -= player.curr_Att;
		player.curr_Hp -= (mob.Att + (int)(mob.Att * mob.Crit));
		std::cout << (mob.Att + (int)(mob.Att * mob.Crit)) << " ���� ũ��Ƽ��!" << endl;
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
	player.curr_Att += 2;							// ������ ���� ���¸� �����ϰ� ���ݷ��� ���� �ȵ� �� �� �־ ����
	//if (player.curr_Att < player.Att) {				
	//	player.curr_Att = player.Att;
	//}
	std::cout << "�⺻ ���ݷ��� 2��ŭ ����" << endl;
	player.Lvl += 1;
	player.Hp += 8;
	std::cout << "�⺻ ü���� 8��ŭ ����" << endl;
	//if (player.curr_Hp < player.Hp) {				// �������� �ߴµ�, �ȿö�����(�� ����? �̰� �ø��� ü�� �������� �ø��ݾ�)
	//	player.curr_Hp = player.Hp;
	//}
	player.Exp = player.Exp - expTable[static_cast<std::vector<int, std::allocator<int>>::size_type>(player.Lvl) - 1];			// ����ġ �ѹ� üũ�غ�����
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
		cerr << "���̺� ����" << endl;
		return;
	}
	// �̸� ����: ���� ���ڿ� ���� ���� ��, ���ڿ� ������ ����
	size_t nameLength = player.Name.size();
	outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
	outFile.write(player.Name.c_str(), nameLength);

	// ���� �� ��Ÿ ��� ����
	outFile.write(reinterpret_cast<const char*>(&player.Att), sizeof(player.Att));
	outFile.write(reinterpret_cast<const char*>(&player.curr_Att), sizeof(player.curr_Att));
	outFile.write(reinterpret_cast<const char*>(&player.Hp), sizeof(player.Hp));
	outFile.write(reinterpret_cast<const char*>(&player.curr_Hp), sizeof(player.curr_Hp));
	outFile.write(reinterpret_cast<const char*>(&player.Exp), sizeof(player.Exp));
	outFile.write(reinterpret_cast<const char*>(&player.Money), sizeof(player.Money));
	outFile.write(reinterpret_cast<const char*>(&player.Lvl), sizeof(player.Lvl));

	std::cout << "���� ����" << endl;
	outFile.close();
	std::system("pause");

	return;
}

Actor Actor::Load()
{
	ifstream inFile("../Data/sav.bin", ios::in | ios::binary);
	if (!inFile.is_open()) {
		cerr << "���̺� ���� ����" << endl;
		return Actor();
	}

	Actor actor;		// �⺻ �����ڸ� ���� �� ��ü ����

	// 1. �̸� ����: ���� �̸� ���̸� �а�, �� ���̸�ŭ ������ ���� �� string�� ����
	size_t nameLength = 0;
	inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

	char* buffer = new char[nameLength + 1];
	inFile.read(buffer, nameLength);
	buffer[nameLength] = '\0';
	actor.Name = buffer;
	delete[] buffer;

	// ���� ��� ����
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

		std::cout << "ȸ����� : 15��" << endl;
		std::cout << "1. ȸ�� 2. �� �ܰ� : ";
		std::cin >> input;

		switch (input) {
		case 1:									// ȸ��
			if (player.Money == 0 || player.Money < 15) {
				std::cout << "������" << endl;
				std::cout << "�i�ܳ���" << endl;
				std::system("pause");
				return;
			}
			if (player.curr_Hp <= player.Hp) {
				player.curr_Hp = player.Hp;
				std::cout << "15�� ���� ȸ��" << endl;
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

		std::cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
		std::cin >> input;
		//mobs = Monster(input);			// ���� ���̽����� ���� ������ �ߴµ�, �׳� ���⼭ üũ�ؾ� �ʵ� ���� �� ���� ������ ���� �ҷ��� �� �ִ�.

		switch (input) {
		case 1:
		{
			Actor mobs("�ʱ�", 3, 30, rand() % 12 + 5, rand() % 15 + 3, rand() % 2 + 1);
			Field_Choose(player, mobs);
			break;
		}
		case 2:
		{
			Actor mobs("�߱�", 6, 60, rand() % 24 + 10, rand() % 30 + 7, rand() % 4 + 2);
			Field_Choose(player, mobs);
			break;
		}
		case 3:
		{
			Actor mobs("���", 9, 90, rand() % 36 + 15, rand() % 45 + 12, rand() % 6 + 4);
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
			array[i][j] = i * 3 + j;			// 3*3�ʵ��� �� �ֱ�
		}
	}

	for (int k = 0; k < 50; k++) {					// ���� ��ġ�� �������� �Ϸ��� ����
		int dst = rand() % 3;
		int src = rand() % 3;

		swap(array[dst][src], array[src][dst]);
	}

	int mob_num = rand() % 8 + 1;		// 0 ���� 1~8������ �� �� ���� �Ѱ��� ��, �� ���� ���� ��ġ

	int (*pArray)[3] = array;
	while (true) {
		std::system("cls");
		for (int i = 0; i < 3; i++) {				// �� ���
			for (int j = 0; j < 3; j++) {
				std::cout << array[i][j] << '\t';
			}
			std::cout << endl;
		}
		int input = 0;
		int zero_i = 0, zero_j = 0;
		player.info();
		std::cout << "2,4,6,8�� �̵�, �Է� : ";
		std::cin >> input;

		for (int i = 0; i < 3; i++) {		//0�� ���� ��ǥ ���
			for (int j = 0; j < 3; j++) {
				if (array[i][j] == 0) {
					zero_i = i;
					zero_j = j;
				}
			}
		}

		int exit = Move(pArray, zero_i, zero_j, input, mob_num, player, mob);

		if (input == 9) {
			std::cout << "��� ����" << endl;
			std::system("pause");
			return;
		}
		if (exit == 99) {
			std::cout << "����� �������� ���ư��ϴ�." << endl;
			std::system("pause");
			return;
		}
	}
}

int Actor::Move(int(*pArray)[3], int i, int j, int input, int mob_Num, Actor& player, Actor& mob)
{
	switch (input) {
	case 2:
		if (i + 1 > 2) {	// �ʵ� �ʸ� �������� �Ұ�
			break;
		}
		if (pArray[i + 1][j] == mob_Num) {
			Battle(player, mob);
			return 99;
		}
		swap(pArray[i][j], pArray[i + 1][j]);
		break;
	case 4:
		if (j - 1 < 0) {	// �ʵ� �ʸ� �������� �Ұ�
			break;
		}
		if (pArray[i][j - 1] == mob_Num) {
			Battle(player, mob);
			return 99;
		}
		swap(pArray[i][j], pArray[i][j - 1]);
		break;
	case 6:
		if (j + 1 > 2) {	// �ʵ� �ʸ� �������� �Ұ�
			break;
		}
		if (pArray[i][j + 1] == mob_Num) {
			Battle(player, mob);
			return 99;
		}
		swap(pArray[i][j], pArray[i][j + 1]);
		break;
	case 8:
		if (i - 1 < 0) {	// �ʵ� �ʸ� �������� �Ұ�
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

	std::cout << "�߻��� ���� " << mob.Name << "�� ��Ÿ����." << endl;		// ��ī���� �޼���
	std::system("pause");
	while (true) {

		std::system("cls");
		player.info();
		mob.mob_Info();

		std::cout << "1. ���� 2. ���� : ";
		std::cin >> input;

		/*int itemdrop = rand() % 5;*/
		switch (input) {
		case 1:
			Fight(player, mob);
			if (mob.Hp <= 0 && player.curr_Hp > 0) {
				std::cout << "�¸�" << endl;
				player.Exp += mob.Exp;
				std::cout << "����ġ�� " << mob.Exp << "��ŭ ȹ�� �߽��ϴ�." << endl;
				if (player.Exp > expTable[player.Lvl]) {
					std::cout << "���� ��" << endl;
					Level_Up(player);

					player.curr_Hp = player.Hp;				// ü��ȸ�� --���������� �ٸ��� ���� ���� ����--
				}// ����ġ ������ ������
				player.Money += mob.Money;
				std::cout << "���� " << mob.Money << "��ŭ ȹ�� �߽��ϴ�." << endl;
				/*if (itemdrop == 2) {*/
				//Armor* droppedArmor = new Armor("� ����", 10, 1.0);
				//obtainItem(droppedArmor);
				//std::cout << droppedArmor->getName() << "ȹ��" << endl;
				//}
				std::system("pause");
				return player;
			}
			else if (player.curr_Hp <= 0) {
				std::cout << "�й�" << endl;
				player.curr_Hp = player.Hp;			// �ʱⰪ��ŭ ȸ��
				player.Exp = (int)(player.Exp * 0.9);		// 10�ۼ�Ʈ�� ����ġ�� ����
				std::cout << "����ġ 10% ����" << endl;
				std::system("pause");
				return player;
			}

			if (player.curr_Hp <= 0 && mob.Hp <= 0) {
				std::cout << "���º�" << endl;
				player.curr_Hp = player.Hp;			// �ʱⰪ��ŭ ȸ��
				player.Exp = (int)(player.Exp * 0.9);		// 10�ۼ�Ʈ�� ����ġ�� ����
				std::cout << "����ġ 10% ����" << endl;
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
