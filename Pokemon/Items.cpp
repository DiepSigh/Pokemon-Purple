#include "Items.h"

Item::Item() {}

Item::Item(std::string name, bool canHeal, int healAmnt, int cost){
	m_ItemName = name;
	m_canHeal = canHeal;
	m_healAmnt = healAmnt;
	m_cost = cost;
}

