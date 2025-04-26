#include "pch.h"
#include "Field_Maps.h"

Field_Maps::Field_Maps()
{
}

Field_Maps::~Field_Maps()
{
}

void Field_Maps::Initialize()
{
	srand(unsigned(time(NULL)));
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

}


void Field_Maps::Update(const Info& player)
{
	srand(unsigned(time(NULL)));
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
		player.print();
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

		int exit = Move(pArray, zero_i, zero_j, input, mob_num, player);

		if (input == 9) {
			std::cout << "��� ����" << endl;
			std::system("pause");
			return;
		}
		if (exit == 99) {
			//std::cout << "����� �������� ���ư��ϴ�." << endl;
			//std::system("pause");
			cout << "���� ����" << endl;
			system("pause");
			return;
		}
	}
}
void Field_Maps::Release()
{
}

int Field_Maps::Move(int(*pArray)[3], int i, int j, int input, int mob_mum, const Info& player) const
{
	switch (input) {
	case 2:
		if (i + 1 > 2) {	// �ʵ� �ʸ� �������� �Ұ�
			break;
		}
		if (pArray[i + 1][j] == mob_mum) {
			return 99;
		}
		swap(pArray[i][j], pArray[i + 1][j]);
		break;
	case 4:
		if (j - 1 < 0) {	// �ʵ� �ʸ� �������� �Ұ�
			break;
		}
		if (pArray[i][j - 1] == mob_mum) {
			return 99;
		}
		swap(pArray[i][j], pArray[i][j - 1]);
		break;
	case 6:
		if (j + 1 > 2) {	// �ʵ� �ʸ� �������� �Ұ�
			break;
		}
		if (pArray[i][j + 1] == mob_mum) {
			return 99;
		}
		swap(pArray[i][j], pArray[i][j + 1]);
		break;
	case 8:
		if (i - 1 < 0) {	// �ʵ� �ʸ� �������� �Ұ�
			break;
		}
		if (pArray[i - 1][j] == mob_mum) {
			return 99;
		}
		swap(pArray[i][j], pArray[i - 1][j]);
		break;
	case 9:
		return 9;
	default:
		return 8;
	}

	return 0;
}
