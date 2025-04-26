#include "pch.h"
#include "MainGame.h"


MainGame::MainGame() : p_Info("����", 100, 10)
{	
	menu = new GameMenu();
	field = new FieldChoose();
	fight = new Fight();
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
}

void MainGame::Update()
{
	int input;
	cout << "���� ����(1. ���� 2. ������ 3. ����) : ";
	cin >> input;

	/*Choose(input);*/
	/*Info();*/

	
	GameMenu gamemenu;
	gamemenu.Update(*this);
}

void MainGame::Release()
{
	delete menu;
	delete field;
	delete fight;
}

void MainGame::ChooseJob()
{
	int input;
	cout << "���� ����(1. ���� 2. ������ 3. ����) : ";
	cin >> input;
	switch (input) {
	case 1:
		p_Info  = Info("����", 100, 10);
		break;
	case 2:
		p_Info = Info("������", 100, 10);
		break;
	case 3:
		p_Info = Info("����", 100, 10);
		break;
	default:
		break;
	}
	
}

void MainGame::showInfo()
{
	cout << "�̸� : " << p_Info.getName() << "\nü�� : "
		<< p_Info.getHp() << "\t���ݷ� : " << p_Info.getAtt() << endl;
}

void MainGame::run()
{
	ChooseJob();
	//showInfo();

	menu = new GameMenu();
	field = new FieldChoose();
	fight = new Fight();

	while (true) {
		menu->Update(*this);
		int level = field->Update(*this);
		if (level == 4) {
			continue;
		}
		fight->Initialize(*this, level);
		cout << "[DEBUG] After Initialize: inBattle=" << 
			"asdf"<</* fight ���� ���� �д� ��� */endl;
		while (fight->Update(level)) {
			cout << "tlqkf" << endl;
		}
	}
}


