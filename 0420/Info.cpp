#include "pch.h"
#include "Info.h"
#include "Global.h"

Info::Info(const string& n, int h, int a) : name(n), hp(h), att(a)
{
}

Info::~Info()
{
}

void Info::Initialize()
{
}

void Info::Update()
{
}

void Info::Release()
{
}

void Info::print() const {
	cout << "이름 : " << name
		<< "\nHp : " << hp
		<< "\tAtt : " << att << endl;
}

string Info::getName() const { return name; }

int Info::getHp() const { return hp; }

int Info::getAtt() const { return att; }

void Info::takeDamage(int d) { hp = max(0, hp - d); }

void Info::setHp(int v) { hp = v; }

void Info::equip(unique_ptr<Item> item)
{
	auto slot = item->getEquipSlot();			/// Item 의 가상 메서드
	if (equipment.count(slot)) {
		// 이미 장착된 아이템은 인벤토리로 되돌리기
		g_inventory.addInven(move(equipment[slot]));
	}
	equipment[slot] = move(item);
}

unique_ptr<Item> Info::unequip(Equipment slot)
{
	auto old = move(equipment[slot]);
	equipment.erase(slot);
	return old;			// 호출부에서 inventory.addInven() 하세요
}

void Info::showEquipment() const
{
	cout << "장착 장비" << endl;
	for (auto const& kv : equipment) {
		Equipment slot = kv.first;
		auto const& item = kv.second;
		cout <<
			static_cast<int>(slot) << ": " <<
			(item ? item->getName() : "없음") <<
			endl;
	}
}
