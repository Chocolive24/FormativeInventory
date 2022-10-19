#pragma once

#include <string>

#include "../Item/Item.h"

#include <vector>

class Inventory
{
private:

	std::vector<Item*> _items;

	void removeItem(Item* item);

public:

	void Add(Item* item);
	void CreateInventory();

	std::string DisplayInventory();
	std::string DisplayPotionPocket();
	std::string DisplayWeaponPocket();

	void ActivateChosenOption();
	void ActivatePotionPocket();
	void ActivateWeaponPocket();

	void UseHealthPotion();  
	void UseStrengthPotion();

	void EquipSword();
	void EquipBow();

	void ConsultMap();

	template<class T> T* GetItem();
};