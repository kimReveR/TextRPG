#include "pch.h"
#include "Item.h"

Item::Item(string n, int extra)
	: Obj(n, extra)
{
}

void Item::Initialize()
{
}

void Item::Update()
{
}

void Item::Render(string str) const
{
	for (int i = 1; i <= 3; i++) {
		cout << i<< ". " << itemName[i - 1] + str;
		if (str == "����") {
			cout << "\t���ݷ�+" << item_Extra[i - 1] << endl;
		}
		else {
			cout << "\tü��+" << item_Extra[i - 1] << endl;
		}
	}
}

void Item::WeaponShop()
{

}

void Item::ArmorShop()
{

}
