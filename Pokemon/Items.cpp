#include "Items.h"

Items::Items() {}

Items::Items(std::string name, int id, int cost, std::string description) {
	
	itemName = name;
	itemId = id;
	itemCost = cost;
	itemDescription = description;

}