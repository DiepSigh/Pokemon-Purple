#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {

public:
	Inventory();
	Inventory(int);
	void AddItem();
	void RemoveItem(); 

	//GETTERS
	int GetMaxCapacity() { return m_maxCapacity; }

	//SETTERS

private:
	int m_maxCapacity;
	vector<std::string> Item;


	void Inventory::AddItem(std::string item) {
		//Item::pop_back();
	};
};

#endif