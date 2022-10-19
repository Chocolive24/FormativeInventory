#pragma once

#include "../../Weapon/Weapon.h"

class Sword : public Weapon
{
public:

	void Use() override;
	void Equip() override;
};

