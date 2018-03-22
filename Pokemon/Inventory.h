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
	int cap;
	int numbOfItems;
	void expand();
	void initialize(const int from);
	Item **itemList;
};

