#include "pch.h"
#include "Fight.h"

Fight::Fight()
{
}

Fight::~Fight()
{

}

void Fight::Initialize()
{
	if (!m_tPlayer || !m_tMonster)
	{
		throw runtime_error("½Ã¹ß");
	}
}

void Fight::Update()
{
	

	int input;
	while (true) {
		m_tPlayer->Render();
		m_tMonster->Render();

		cout << "1. °ø 2. µµ¸Á : ";
		cin >> input;

		if (input == 1) {
			m_tPlayer->Damage(m_tMonster->getAtt());
			m_tMonster->Damage(m_tPlayer->getAtt());
			if (m_tPlayer->getHp() <= 0) {
				cout << "ÆÐ¹è" << endl;
				m_tPlayer->setHp(100);
				return;
			}
			if(m_tMonster->getHp() <= 0) {
				cout << "½Â¸®" << endl;
				return;
			}
		}
		else if (input == 2) {
			return;
		}
	}
 	


}
