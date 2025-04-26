#pragma once

#ifndef TEXTRPG_H
#define TEXTRPG_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<vector>
#include<string>
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

using namespace std;



#endif
#endif

#endif // !ACTOR_H
