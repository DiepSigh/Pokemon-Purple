#include "Inventory.h"

Inventory::Inventory()
{
	cap = 10;
	this->numbOfItems = 0;
	this->itemList = new Item*[cap];
}

Inventory::~Inventory()
{
	for (int i = 0; i < this->numbOfItems; i++)
	{
		delete this->itemList[i];
	}
	delete[] itemList;
}

void Inventory::expand() {

	this->cap *= 2;
	Item **tempitemList = new Item*[this->cap];

	for (int i = 0; i < this->numbOfItems; i++)
	{
		tempitemList[i] = new Item(*this->itemList[i]);
	}

	for (int i = 0; i < this->numbOfItems; i++)
	{
		delete this->itemList[i];
	}
	delete[] this->itemList;

	this->itemList = tempitemList;

	this->initialize(this->numbOfItems);
}

void Inventory::addItem(const Item &item)
{
	if (this->numbOfItems >= this->cap) {
		expand();
	}
	this->itemList[this->numbOfItems++] = new Item(item);
}

void Inventory::removeItem(string itemName) {

}

void Inventory::initialize(const int from) 
{
	for (int i = from; i < cap; i++)
	{
		this->itemList[i] = nullptr;
	}
}