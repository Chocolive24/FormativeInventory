#pragma once

#include "../../Item/Item.h"

enum class MapName
{
	SAE,
	KANTO,

};

class Map : public Item
{
private:

	MapName _name;

public:

	Map(MapName name);

	MapName GetMapName() { return _name; }

	void Use() override;
};