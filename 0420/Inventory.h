#pragma once
#include "pch.h"
#include "Item.h"

class Inventory
{
private:
	vector<unique_ptr<Item>>items;
public:
	Inventory();
	Inventory(const std::string& name, const std::string& part, int extraHp, int price);
	~Inventory();

public:
	void Initialize();
	void Update();
	void Release();

	void clear() { items.clear(); }		// 인벤 비우기

	void addInven(unique_ptr<Item> item);		// 인벤토리에 아이템 들어가기

	// 저장/로드 시 벡터를 직접 읽어 올 수 있게
	const std::vector<std::unique_ptr<Item>>& getItems() const;

	void List() const;					// 인벤토리의 아이템 전부 보여주기
};

