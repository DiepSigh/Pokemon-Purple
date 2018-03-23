#ifndef ITEMS_H
#define ITEMS_H


#include <string>
using namespace std;


class Items {
public:

	Items();
	Items(std::string);
	//GETTERS
	string GetItemName() { return itemName; }
	//SETTERS
	void SetItemNAme(std::string name) { itemName = name; }

private:
	std::string itemName;
};

#endif // !ITEMS_H
