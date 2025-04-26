#include "pch.h"
#include "Item.h"

Item::Item(const string& name, int price)
	: name(name), price(price)
{
}

Item::~Item()
{
}

void Item::Initialize()
{
}

void Item::Update()
{
}

void Item::Release()
{
}

string Item::getName() const
{
	return name;
}

int Item::getPrice() const
{
	return price;
}

void Item::setName(string n)
{
	name = n;
}

void Item::setPrice(int p)
{
	price = p;
}

