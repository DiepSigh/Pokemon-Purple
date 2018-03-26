#include "inventory.h"

Inventory::Inventory() {}

Inventory::Inventory(int capacity) {
	m_Capacity = capacity;
	};

void Inventory::AddItem(Item item) {
	playerInventory.push_back(item);
};
//REmoveItem