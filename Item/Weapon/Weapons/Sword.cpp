#include "Sword.h"

#include <iostream>

// ------------------------------------------------------------------------------------------------------------------------------

void Sword::Use()
{
	if (_equipped)
	{
		std::cout << "You dealt damages with your sword." << std::endl << std::endl;
	}

	else
	{
		std::cout << "You haven't equipped your sword..." << std::endl << std::endl;
	}
}

// ------------------------------------------------------------------------------------------------------------------------------

void Sword::Equip()
{
	_equipped = true;
	std::cout << "You equipped your sword." << std::endl << std::endl;
}

// ------------------------------------------------------------------------------------------------------------------------------