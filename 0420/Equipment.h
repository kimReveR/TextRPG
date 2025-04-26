#pragma once
#include "pch.h"
enum class Equipment
{
	Head, Chest, Legs, Gloves, Boots, Weapon
};

static const map<Equipment, string> SlotNames = {
	{Equipment::Head, "����"},
	{Equipment::Chest, "����"},
	{Equipment::Legs, "����"},
	{Equipment::Gloves, "�尩"},
	{Equipment::Boots, "�Ź�"},
	{Equipment::Weapon, "����"}
};

