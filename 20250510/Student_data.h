#pragma once
#include "pch.h"

typedef struct student {
public:
	string name;

	int korean;
	int math;
	int english;

	int total;

	float average;

	student() : name(""), korean(0), math(0), english(0), total(0), average(0.f) {};
	student(string n, int k, int m, int e) : name(n), korean(k), math(m), english(e) {
		total = korean + math + english;
		average = (float)total / 3;
	}

	virtual void Render() const {
		cout << "이름 : " << name << "\t국어 : " << korean << "\t수학 : " << math << "\t영어 : " << english
			<< "\n총점 : " << total << "\t평균 : " << average << endl;
	}
}INFO;

extern vector<student> dent;		// 외부에서도 사용하게 extern으로 선언