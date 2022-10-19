#pragma once

#include "../Weapon.h"

class Bow : public Weapon
{
public:

	void Use() override;
	void Equip() override;
};

