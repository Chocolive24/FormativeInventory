#pragma once

#include "../Item/Item.h"
#include "../Item/Map/Map.h"

#include <string>
#include <vector>

class Inventory
{
private:

	std::vector<Item*> _items;

	void removeItem(Item* item);

public:

	// Functions to create the inventory and to add items in it.
	void Add(Item* item);
	void CreateInventory();

	// Functions to display the interfaces 
	std::string DisplayInventory();
	std::string DisplayPotionPocket();
	std::string DisplayWeaponPocket();
	std::string DisplayMapPocket();

	// Activate the menus and the options 
	void ActivateChosenOption();
	void ActivatePotionPocket();
	void ActivateWeaponPocket();
	void ActivateMapPocket();

	void UseHealthPotion();  
	void UseStrengthPotion();

	void EquipSword();
	void EquipBow();

	template<class T> T* GetItem();
	template<class T> T* GetMap(std::string name);
};