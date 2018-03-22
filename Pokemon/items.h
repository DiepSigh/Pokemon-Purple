#ifndef ITEMS_H
#define ITEMS_H

#include <string>
using namespace std;

class Item {
public:
	Item();
	Item(string, bool, int, int);
	virtual ~Item();	//GETTER

	//SETTER

private:
	string m_ItemName;
	int m_healAmnt;
	bool m_canHeal;
	int m_cost;

};
#endif // !ITEMS_H
