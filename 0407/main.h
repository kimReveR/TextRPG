#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<vector>
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
using namespace std;

typedef struct Object {
	char Name[32] = "";
	int Att;					// 기본 공격력(레벨에 따라 증가)
	int curr_Att;				// 최종 공격력(디버프, 버프, 장비에 따라 증가,감소)
	int Hp;						// 기본 체력(부활할 때의 기본 체력, 레벨에 따라 증가)
	int curr_Hp;				// 최종 체력(디버프, 버프, 장비에 따라 증가, 감소)
	int Exp;					// 경험치
	int Money;					// 소지금
	int Lvl;					// 레벨(방어력도 겸하게 할까 생각중)

	//string* sArr;		// 동적 배열을 가리킨는 포인터
}OBJ;
#endif
#endif

