#include "Inventory.h"

Inventory::Inventory()
{
	this->numbOfItems = 0;
	this->itemList = new Item*[numbOfItems];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->numbOfItems; i++)
	{
		delete this->itemList[i];
	}
	delete[] itemList;
}

void Inventory::expand() {

}
void Inventory::addItem(const Item &item) {

}


void Inventory::removeItem(string itemName) {

}


void Inventory::initialize() {

}