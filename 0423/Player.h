#pragma once
#include "Character.h"

class Player : public Character
{

public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Release();

	void Render() const override;

	void Damage(int dmg) { CHp -= dmg; };

};

