#pragma once
#include "Obj.h"

class Item : public Obj
{
protected:
	string itemName[3] = { "�ʱ�", "�߱�", "���" };
	int item_Extra[3] = { 3,6,9 };
public:
	Item() : Obj("",0) {};
	Item(string n, int extra);		// extra�� �߰� ���ݷ� �̰ų� �߰� ü��
	~Item() {};

	void Initialize() override;
	void Update() override;
	void Render(string str) const;

	void WeaponShop();
	void ArmorShop();
};

