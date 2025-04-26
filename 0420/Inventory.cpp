#include "pch.h"
#include "Inventory.h"
#include "Armor.h"

Inventory::Inventory()
{
}

Inventory::Inventory(const std::string& name, const std::string& part, int extraHp, int price)
{
}

Inventory::~Inventory()
{
}

void Inventory::Initialize()
{
}

void Inventory::Update()
{
}

void Inventory::Release()
{
}

void Inventory::addInven(unique_ptr<Item> item)
{
	items.push_back(move(item));
}

// ����/�ε� �� ���͸� ���� �о� �� �� �ְ�
const std::vector<std::unique_ptr<Item>>& Inventory::getItems() const {
	return items;
}

void Inventory::List() const
{
	if (items.empty()) {
		cout << "�������" << endl;
	}
    for (auto& p : items) {
        std::cout << "�̸�: " << p->getName()
            << " | ����: " << p->getPrice();
        if (p->getTypeId() == ItemType::Armor) {
            auto* a = static_cast<Armor*>(p.get());
            std::cout << " | ����: " << a->getPartName()
                << " | ü��+: " << a->getE_Hp();
        }
        std::cout << "\n";
    }
}
