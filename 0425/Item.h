#pragma once
#include "Obj.h"

class Item : public Obj
{
protected:
	string itemName[3] = { "초급", "중급", "고급" };
	int item_Extra[3] = { 3,6,9 };
public:
	Item() : Obj("",0) {};
	Item(string n, int extra);		// extra는 추가 공격력 이거나 추가 체력
	~Item() {};

	void Initialize() override;
	void Update() override;
	void Render(string str) const;

	void WeaponShop();
	void ArmorShop();
};

