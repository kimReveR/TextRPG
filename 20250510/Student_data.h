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
		cout << "�̸� : " << name << "\t���� : " << korean << "\t���� : " << math << "\t���� : " << english
			<< "\n���� : " << total << "\t��� : " << average << endl;
	}
}INFO;

extern vector<student> dent;		// �ܺο����� ����ϰ� extern���� ����