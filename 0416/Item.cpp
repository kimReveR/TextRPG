#include "Item.h"


//Armor(const string& part, int extraHp, double number) :
//	Item(Name, Price), ArmorPart(part), E_Hp(extraHp), Number(number) {
//
//	int R_Num = rand() % 4 + 1;
//	ArmorPart = partName[R_Num];
//	int R_Num2 = rand() % 3 + 1;
//	Item.Name = prefix[R_Num2] + partName[R_Num];
//	E_Hp = HP_Check(Name);
//	Price = Price_Check(Name);
//	Number = rand() % 1235851 + 1;
//};

// vector<string> prefix{ "쓸만한 ", "폐기 직전의 ", "거의 새것 같은 ", "낡은 " };
int Armor::HP_Check(std::string prefix)
{
	int extraHp = 0;
	if (prefix.find("쓸만한 ") != string::npos) {
		return extraHp = 15;
	}
	else if (prefix.find("거의 새것 같은 ") != string::npos) {
		return extraHp = 25;
	}
	else if (prefix.find("낡은 ") != string::npos) {
		return extraHp = 8;
	}
	else if (prefix.find("폐기 직전의 ") != string::npos) {
		return extraHp = 3;
	}
	else {
		return 0;
	}

	return 0;
}

int Armor::Price_Check(std::string prefix)
{
	int price = 0;
	if (prefix.find("쓸만한 ") != string::npos) {
		return price = 13;
	}
	else if (prefix.find("거의 새것 같은 ") != string::npos) {
		return price = 18;
	}
	else if (prefix.find("낡은 ") != string::npos) {
		return price = 5;
	}
	else if (prefix.find("폐기 직전의 ") != string::npos) {
		return price = 1;
	}
	else {
		return 0;
	}
	return 0;
}

Armor::~Armor()
{
}


