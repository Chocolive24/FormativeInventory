#include "Bow.h"

#include <iostream>

// ------------------------------------------------------------------------------------------------------------------------------

void Bow::Use()
{
	if (_equipped)
	{
		std::cout << "You dealt damages with your bow." << std::endl << std::endl;
	}

	else
	{
		std::cout << "You haven't equipped your bow..." << std::endl << std::endl;
	}
}

// ------------------------------------------------------------------------------------------------------------------------------

void Bow::Equip()
{
	_equipped = true;
	std::cout << "You equipped your bow." << std::endl << std::endl;
}

// ------------------------------------------------------------------------------------------------------------------------------