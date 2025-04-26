#pragma once
#include "pch.h"
//#include "Player.h"
//#include "Monster.h"

class Obj
{
protected:					// �÷��̾�, ���� ��� �̸�, ü��, ���ݷ��̶�� ����� ������ �ʿ�
	string name;
	int hp{};
	int att{};

public:
	Obj();
	Obj(string n, int hp, int att);
	Obj(string n, int extra);
	virtual ~Obj() {};

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void SetHp(int hp);			// �÷��̾� ��� ���� ��Ȱ�� �� ü���� �ǵ�����.

	virtual void Render() const;			// ��µ� ���⼭ ó��

	void SetDamage(int dmg);		// ������ �����°͵� ó��

	int GetAtt() const;				// ������ ���� ��, ���ݷ��� �˾ƾ� �ϴ�, get()���� ���ݷ��� �޾ƿ�
	int GetHp() const;				// �÷��̾�, ������ ü�¿� ���� �¸�, �й� ó���� �ؾߵǼ� get()���� ü���� �޾ƿ�
};

