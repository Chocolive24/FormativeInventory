#pragma once

#include "../../Item/Item.h"

#include <string>

class Map : public Item
{
private:

	std::string _name;

public:

	Map(std::string name);

	std::string GetName() { return _name; }

	void Use() override;
};