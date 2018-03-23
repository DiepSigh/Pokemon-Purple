#include "inventory.h"
#include "items.h"
#include <vector>

Inventory::Inventory() {}

Inventory::Inventory( int maxCapacity ) {
	m_maxCapacity = maxCapacity;
};