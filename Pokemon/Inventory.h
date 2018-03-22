#pragma once
#include "items.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	void addItem(const Item &item);
	void removeItem(string itemName);
private:
	int numbOfItems;
	void expand();
	void initialize();
	Item **itemList;
};

