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
		throw runtime_error("�ù�");
	}
}

void Fight::Update()
{
	

	int input;
	while (true) {
		m_tPlayer->Render();
		m_tMonster->Render();

		cout << "1. �� 2. ���� : ";
		cin >> input;

		if (input == 1) {
			m_tPlayer->Damage(m_tMonster->getAtt());
			m_tMonster->Damage(m_tPlayer->getAtt());
			if (m_tPlayer->getHp() <= 0) {
				cout << "�й�" << endl;
				m_tPlayer->setHp(100);
				return;
			}
			if(m_tMonster->getHp() <= 0) {
				cout << "�¸�" << endl;
				return;
			}
		}
		else if (input == 2) {
			return;
		}
	}
 	


}
