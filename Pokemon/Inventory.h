#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "items.h"


class Inventory {

public:
	Inventory();
	Inventory(int);

	void AddItem(Item item);
	//void RemoveItem(Item item);

	//GETTERS
	int GetCapacity() { return m_Capacity; }

	//SETTERS
	void SetCapacity(int capacity) { m_Capacity = capacity; }

private:
	int m_Capacity = 0;
	std::vector<Item>  playerInventory;
};

class playerInventory : public Inventory {
public:

};
#endif
