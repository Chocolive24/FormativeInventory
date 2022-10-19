#include "Inventory.h"

#include <iostream>
#include "../Item/Potion/Potions/HealthPotion.h"
#include "../Item/Potion/Potions/StrengthPotion.h"
#include "../Item/Weapon/Weapons/Sword.h"
#include "../utility/Utility.h"
#include "../Item/Weapon/Weapons/Bow.h"
#include "../Item/Map/Map.h"

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::removeItem(Item* item)
{
	_items.erase(std::remove(_items.begin(), _items.end(), item), _items.end());
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::Add(Item* item)
{
	_items.emplace_back(item);
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::CreateInventory()
{
	auto* healthPotion = new HealthPotion;
	auto* healthPotion2 = new HealthPotion;
	auto* strengthPotion = new StrengthPotion;

	Add(healthPotion);
	Add(healthPotion2);
	Add(strengthPotion);

	auto* sword = new Sword;
	auto* bow = new Bow;

	Add(sword);
	Add(bow);

	auto* map = new Map;
	Add(map);
}

// ------------------------------------------------------------------------------------------------------------------------------

std::string Inventory::DisplayInventory()
{
	// Show the user the possible options of the program.
	std::cout << "====================Inventory===================" << std::endl;
	std::cout << "[1] To go to Potion pocket.					  " << std::endl;
	std::cout << "[2] To go to the Weapon pocket.				  " << std::endl;
	std::cout << "[3] To go to the Map pocket.			          " << std::endl;
	std::cout << "[4] To quite to program.						  " << std::endl;
	std::cout << "================================================" << std::endl;

	// Get the option chosen by the user.
	std::string userAnswer = Utility::GetNumberTyped();
	system("cls");

	return userAnswer;
}

// ------------------------------------------------------------------------------------------------------------------------------

std::string Inventory::DisplayPotionPocket()
{
	std::cout << "=============Potion============" << std::endl;
	std::cout << "[1] To use a Health Potion.    " << std::endl;
	std::cout << "[2] To use a Strength Potion.  " << std::endl;
	std::cout << "[3] Back.  					 " << std::endl;
	std::cout << "===============================" << std::endl;

	// Get the option chosen by the user.
	std::string userAnswer = Utility::GetNumberTyped();
	system("cls");

	return userAnswer;
}

// ------------------------------------------------------------------------------------------------------------------------------

std::string Inventory::DisplayWeaponPocket()
{
	std::cout << "===========Weapon==========" << std::endl;
	std::cout << "[1] To equip your Sword.   " << std::endl;
	std::cout << "[2] To equip your Bow.     " << std::endl;
	std::cout << "[3] To use your Weapon.    " << std::endl;
	std::cout << "[4] Back.  				 " << std::endl;
	std::cout << "===========================" << std::endl;

	// Get the option chosen by the user.
	std::string userAnswer = Utility::GetNumberTyped();
	system("cls");

	return userAnswer;
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::ActivatePotionPocket()
{
	do
	{
		std::string userAnswer = DisplayPotionPocket();

		if (userAnswer == "1")
		{
			UseHealthPotion();
		}

		else if (userAnswer == "2")
		{
			UseStrengthPotion();
		}

		else
		{
			break;
		}

	} while (true);
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::ActivateWeaponPocket()
{
	auto* sword = GetItem<Sword>();
	auto* bow = GetItem<Bow>();

	do
	{
		std::string userAnswer = DisplayWeaponPocket();

		if (userAnswer == "1")
		{
			EquipSword();
			bow->SetState(false);
		}

		else if (userAnswer == "2")
		{
			EquipBow();
			sword->SetState(false);
		}

		else if (userAnswer == "3")
		{
			if (sword->GetState())
			{
				sword->Use();
			}

			else if (bow->GetState())
			{
				bow->Use();
			}

			else
			{
				std::cout << "You have not equipped a weapon..." << std::endl << std::endl;
			}
		}

		else
		{
			break;
		}

	} while (true);
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::ActivateChosenOption()
{
	do
	{
		std::string userAnswer = DisplayInventory();

		if (userAnswer == "1")
		{
			ActivatePotionPocket();
		}

		else if (userAnswer == "2")
		{
			ActivateWeaponPocket();
		}

		else if (userAnswer == "3")
		{
			ConsultMap();
		}

		else
		{
			break;
		}

	} while (true);
	
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::UseHealthPotion()
{
	auto* healthPotion = GetItem<HealthPotion>();

	if (healthPotion == nullptr)
	{
		std::cout << "You have no more health potion..." << std::endl << std::endl;
	}

	else
	{
		healthPotion->Use();
		removeItem(healthPotion);
	}
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::UseStrengthPotion()
{
	auto* strengthPotion = GetItem<StrengthPotion>();

	if (strengthPotion == nullptr)
	{
		std::cout << "You have no more strength potion..." << std::endl << std::endl;
	}

	else
	{
		strengthPotion->Use();
		removeItem(strengthPotion);
	}
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::EquipSword()
{
	auto* sword = GetItem<Sword>();

	if (sword == nullptr)
	{
		std::cout << "You have no sword..." << std::endl << std::endl;
	}

	else
	{
		sword->Equip();
	}
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::EquipBow()
{
	auto* bow = GetItem<Bow>();

	if (bow == nullptr)
	{
		std::cout << "You have no bow..." << std::endl << std::endl;
	}

	else
	{
		bow->Equip();
	}
}

// ------------------------------------------------------------------------------------------------------------------------------

void Inventory::ConsultMap()
{
	auto* map = GetItem<Map>();

	if (map == nullptr)
	{
		std::cout << "You have no map..." << std::endl << std::endl;
	}

	else
	{
		map->Use();
	}
}

// ------------------------------------------------------------------------------------------------------------------------------

template <class T> T* Inventory::GetItem()
{
	for (Item* item : _items)
	{
		if (T* tItem = dynamic_cast<T*>(item))
		{
			return tItem;
		}
	}

	return nullptr;
}

// ------------------------------------------------------------------------------------------------------------------------------