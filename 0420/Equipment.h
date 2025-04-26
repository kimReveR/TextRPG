#pragma once
#include "pch.h"
enum class Equipment
{
	Head, Chest, Legs, Gloves, Boots, Weapon
};

static const map<Equipment, string> SlotNames = {
	{Equipment::Head, "투구"},
	{Equipment::Chest, "상의"},
	{Equipment::Legs, "하의"},
	{Equipment::Gloves, "장갑"},
	{Equipment::Boots, "신발"},
	{Equipment::Weapon, "무기"}
};

