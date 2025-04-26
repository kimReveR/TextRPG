#pragma once

class Info;

class FieldChoose {
public:
	FieldChoose();
	~FieldChoose();
public:
	void Initialize();
	int Update(const Info& player);
	void Release();
};

