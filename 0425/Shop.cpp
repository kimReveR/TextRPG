#include "pch.h"
#include "Shop.h"

void Shop::Initialize()
{
}

void Shop::Release()
{
}

void Shop::Update()
{
	int input;
	while (true) {
		cout << "1. ���� 2. �� 3. �ڷ�";
		cin >> input;
		switch (input) {
		case 1:
			Weapon();
			break;
		case 2:
			Armor();
			break;
		case 3:
			return;
		}
	}

}

void Shop::Weapon()
{
	int input;
	items.WeaponShop();
	while (true) {
		items.Render("����");
		cout << "��� ° ���� ����?(�ڷΰ��� : 4) : ";
		cin >> input;

		int buy;
		switch (input) {
		case �ʱ�:
			cout << "����?\n1. ���� 2. ��� : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "���� �Ϸ�" << endl;
			}
			else {
				cout << "���� ���" << endl;
				return;
			}
			break;
		case �߱�:
			cout << "����?\n1. ���� 2. ��� : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "���� �Ϸ�" << endl;
			}
			else {
				cout << "���� ���" << endl;
				return;
			}
			break;
		case ���:
			cout << "����?\n1. ���� 2. ��� : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "���� �Ϸ�" << endl;
			}
			else {
				cout << "���� ���" << endl;
				return;
			}
			break;
		case 4:
			return;
		}
	}
}

void Shop::Armor()
{
	int input;
	while (true) {
		items.Render("��");
		cout << "��� ° �� ����?(�ڷΰ��� : 4) : ";
		cin >> input;

		int buy;
		switch (input) {
		case �ʱ�:
			cout << "����?\n1. ���� 2. ��� : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "���� �Ϸ�" << endl;
			}
			else {
				cout << "���� ���" << endl;
				return;
			}
			break;
		case �߱�:
			cout << "����?\n1. ���� 2. ��� : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "���� �Ϸ�" << endl;
			}
			else {
				cout << "���� ���" << endl;
				return;
			}
			break;
		case ���:
			cout << "����?\n1. ���� 2. ��� : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "���� �Ϸ�" << endl;
			}
			else {
				cout << "���� ���" << endl;
				return;
			}
			break;
		case 4:
			return;
		}
	}
}

bool Shop::Buy_Confirm(int buy)
{
	if (buy == 1) {
		return true;
	}
	if (buy == 2) {
		return false;
	}
	else {
		return false;
	}
}
