#include "pch.h"
#include "Load.h"
#include "Armor.h"

Load::Load()
{
}

Load::~Load()
{
}

void Load::Initialize()
{
}

bool Load::Update(const string& path,
	Info& player,
	Inventory& inv)
{
	ifstream load(path, ios::in | ios::binary);
	if (!load.is_open()) {
		cerr << "���̺� ���� ����" << endl;
		return false;
	}
	// �÷��̾� ���� �ε�
	{
		size_t nameLength = 0;
		load.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

		string name(nameLength, '\0');
		load.read(&name[0], nameLength);

		int att = 0, hp = 0;
		load.read(reinterpret_cast<char*>(&att), sizeof(att));
		load.read(reinterpret_cast<char*>(&hp), sizeof(hp));

		player = Info(name, hp, att);
	}
	// �κ��丮 ���� �ε�
	inv.clear();
	{
		size_t count = 0;
		load.read(reinterpret_cast<char*>(&count), sizeof(count));
		for (size_t i = 0; i < count; ++i) {
			int typeId = 0;
			load.read((char*)&typeId, sizeof(typeId));

			// �̸�
			size_t nameLength = 0;
			load.read((char*)&nameLength, sizeof(nameLength));
			string name(nameLength, '\0');
			load.read(&name[0], nameLength);

			//����
			int price = 0;
			load.read((char*)&price, sizeof(price));

			if (typeId == static_cast<int>(ItemType::Armor)) {
				// ����
				size_t partNameLength = 0;
				load.read((char*)&partNameLength, sizeof(partNameLength));

				string partname(partNameLength, '\0');
				load.read(&partname[0], partNameLength);

				int extrahp = 0;
				load.read((char*)&extrahp, sizeof(extrahp));

				auto ptr = make_unique<Armor>(partname, extrahp);
				ptr->setName(name);
				ptr->setPrice(price);
				inv.addInven(move(ptr));
			}

		}
	}
	load.close();
	return true;
}

void Load::Release()
{
}
