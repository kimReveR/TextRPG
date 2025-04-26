#include "pch.h"
#include "MainGame.h"


MainGame::MainGame()
{
	m_tPlayer = nullptr;
	m_tField = nullptr;
}

MainGame::~MainGame()
{
}

void MainGame::Initialize()
{
	if (!m_tPlayer) {
		m_tPlayer = new Player;
	}
	m_tPlayer->Update();

	if (!m_tField) {
		m_tField = new Field;
	}
	m_tField->Initialize();
	m_tField->setPlayer(m_tPlayer);
}

void MainGame::Update()
{
	int input;
	while (true) {
		m_tPlayer->Render();
		cout << "1. 필드 2. 종료 : ";
		cin >> input;
		
		switch (input) {
		case 1:
			m_tField->Update();
			break;
		case 2:
			return;
		}
	}
	
	
}

void MainGame::Release()
{
	delete m_tPlayer;
}
