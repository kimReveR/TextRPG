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

	void clear() { items.clear(); }		// �κ� ����

	void addInven(unique_ptr<Item> item);		// �κ��丮�� ������ ����

	// ����/�ε� �� ���͸� ���� �о� �� �� �ְ�
	const std::vector<std::unique_ptr<Item>>& getItems() const;

	void List() const;					// �κ��丮�� ������ ���� �����ֱ�
};

