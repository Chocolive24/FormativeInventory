#include "Map.h"

#include <iostream>

// ------------------------------------------------------------------------------------------------------------------------------

Map::Map(std::string name)
{
	_name = name;
}

// ------------------------------------------------------------------------------------------------------------------------------

void Map::Use()
{
	if (_name == "Sae")
	{
		std::cout << "You're in Sae Institute in Geneva (very cool HighSchool btw)." << std::endl << std::endl;
	}

	else if (_name == "Kanto")
	{
		std::cout << "You're in the Kanto region. Try to catch'em all !" << std::endl << std::endl;
	}
	
}

// ------------------------------------------------------------------------------------------------------------------------------