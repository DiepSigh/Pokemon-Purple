#ifndef ITEMS_H
#define ITEMS_H

#include <string>


class Items {
public:

	Items();
	Items(std::string, int, int, std::string);
	//GETTERS
	std::string GetName() { return itemName; }
	int GetId() { return itemId; }
	int GetCost() { return itemCost; }
	std::string GetItemDescription() { return itemDescription; }

	//SETTERS
	void SetName(std::string name) { itemName = name; }
	void SetId(int id) { itemId = id; }
	void SetCost(int cost) { itemCost = cost; }
	void SetDescription(std::string description) { itemDescription = description; }

private:
	std::string itemName;
	int itemId;
	int itemCost;
	std::string itemDescription;

};

#endif // !ITEMS_H
