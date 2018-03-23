#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>


class Inventory {

public:
	Inventory();
	Inventory(int);
	void AddItem(Item item);
	//void AddItem(Item item);
	void RemoveItem();

	//GETTERS
	int GetCapacity() { return m_Capacity; }

	//SETTERS
	void SetCapacity(int capacity) { m_Capacity = capacity; }

private:
	int m_Capacity;
	std::vector<Item>  playerInventory;
};

class PlayerInventory : public Inventory {
public:
	int m_Capacity = 99;
};
#endif
