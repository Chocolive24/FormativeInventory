#pragma once

#include "../../Item/Item.h"

class Weapon : public Item
{
protected:
	bool _equipped = false;

public:
	bool GetState() { return _equipped; }
	bool SetState(bool equipped) { return _equipped = equipped; }
	virtual void Equip() = 0;
};