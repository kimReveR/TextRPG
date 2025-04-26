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

// 저장/로드 시 벡터를 직접 읽어 올 수 있게
const std::vector<std::unique_ptr<Item>>& Inventory::getItems() const {
	return items;
}

void Inventory::List() const
{
	if (items.empty()) {
		cout << "비어있음" << endl;
	}
    for (auto& p : items) {
        std::cout << "이름: " << p->getName()
            << " | 가격: " << p->getPrice();
        if (p->getTypeId() == ItemType::Armor) {
            auto* a = static_cast<Armor*>(p.get());
            std::cout << " | 부위: " << a->getPartName()
                << " | 체력+: " << a->getE_Hp();
        }
        std::cout << "\n";
    }
}
