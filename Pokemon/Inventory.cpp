#include "inventory.h"

Inventory* Inventory::sInstance = nullptr;
bool Inventory::sInitialized = false;

Inventory::Inventory() {}

Inventory::Inventory(int capacity) {
	m_Capacity = capacity;
	};

void Inventory::AddItem(Item item) {
	playerInventory.push_back(item);
};
//REmoveItem