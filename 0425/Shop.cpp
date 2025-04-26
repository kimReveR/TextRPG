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
		cout << "1. 무기 2. 방어구 3. 뒤로";
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
		items.Render("무기");
		cout << "몇번 째 무기 선택?(뒤로가기 : 4) : ";
		cin >> input;

		int buy;
		switch (input) {
		case 초급:
			cout << "구매?\n1. 구매 2. 취소 : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "구매 완료" << endl;
			}
			else {
				cout << "구매 취소" << endl;
				return;
			}
			break;
		case 중급:
			cout << "구매?\n1. 구매 2. 취소 : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "구매 완료" << endl;
			}
			else {
				cout << "구매 취소" << endl;
				return;
			}
			break;
		case 고급:
			cout << "구매?\n1. 구매 2. 취소 : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "구매 완료" << endl;
			}
			else {
				cout << "구매 취소" << endl;
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
		items.Render("방어구");
		cout << "몇번 째 방어구 선택?(뒤로가기 : 4) : ";
		cin >> input;

		int buy;
		switch (input) {
		case 초급:
			cout << "구매?\n1. 구매 2. 취소 : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "구매 완료" << endl;
			}
			else {
				cout << "구매 취소" << endl;
				return;
			}
			break;
		case 중급:
			cout << "구매?\n1. 구매 2. 취소 : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "구매 완료" << endl;
			}
			else {
				cout << "구매 취소" << endl;
				return;
			}
			break;
		case 고급:
			cout << "구매?\n1. 구매 2. 취소 : ";
			cin >> buy;
			if (Buy_Confirm(buy)) {
				cout << "구매 완료" << endl;
			}
			else {
				cout << "구매 취소" << endl;
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
