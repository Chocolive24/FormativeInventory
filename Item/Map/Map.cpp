#include "Map.h"

#include <iostream>

// ------------------------------------------------------------------------------------------------------------------------------

Map::Map(MapName name)
{
	_name = name;
}

// ------------------------------------------------------------------------------------------------------------------------------

void Map::Use()
{
	if (_name == MapName::SAE)
	{
		std::cout << "You're in Sae Institute in Geneva (very cool HighSchool btw)." << std::endl << std::endl;
	}

	else if (_name == MapName::KANTO)
	{
		std::cout << "You're in the Kanto region. Try to catch'em all !" << std::endl << std::endl;
	}
	
}

// ------------------------------------------------------------------------------------------------------------------------------