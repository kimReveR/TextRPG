#include "pch.h"
#include "Fight.h"
#include "Item.h"
#include "Armor.h"
#include "Global.h"


Fight::Fight()
{
}

Fight::~Fight()
{
}

void Fight::Initialize(const Info& player, int level) {
	mob.Create(level);
}

bool Fight::Update(Info& player) {
	system("cls");
	player.print();
	mob.print();
	cout << "1. 공격 2. 도망";
	int input;
	cin >> input;
	if (input == 2) {
		cout << "도망" << endl;
		system("pause");
		return false;
	}

	mob.takeDamage(player.getAtt());
	if (mob.getHp() <= 0) {
		cout << "승리" << endl;
		auto ptr = std::make_unique<Armor>("", 10);
		cout << ptr->getName() << " 획득" << endl;
		// 여기에 부위별 추가 체력이랑 비교해서 습득한 아이템의 추가 스탯이 더 좋으면 장착
		player.equip(move(ptr));
		// 아니면 인벤토리로 들어감
		//g_inventory.addInven(move(ptr));
		system("pause");
		return false;
	}

	player.takeDamage(mob.getAtt());
	if (player.getHp() <= 0) {
		cout << "패배" << endl;
		player.setHp(100);
		system("pause");
		return false;
	}
	return true;
}

void Fight::Release()
{
}
