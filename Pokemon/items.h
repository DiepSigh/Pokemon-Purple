#ifndef ITEMS_H
#define ITEMS_H

#include <string>

class Item {
public:
	Item();
	Item( std::string, int, int, std::string );

	//GETTERS
	std::string GetItemName() { return m_itemName; }
	int GetId() { return m_itemId; }
	int GetCost() { return m_itemCost; }
	std::string GetItemDescription() { return m_itemDescription; }

	//SETTERS
	void SetItemName(std::string name) { m_itemName = name; }
	void SetItemId(int id) { m_itemId = id; }
	void SetItemCost(int cost) { m_itemCost = cost; }
	void SetItemDescription(std::string description) { m_itemDescription = description; }

private:
	std::string m_itemName;
	int m_itemId;
	int m_itemCost;
	std::string m_itemDescription;
};

class Potion : public Item
{
public:
	std::string m_itemName = "Potion";
	int m_itemId = 01;
	int m_itemCost = 300;
	std::string m_itemDescription = "Heals 20 HP to a Pokémon./n";

};

class Antidote : public Item
{
public:
	std::string m_itemName = "Antidote";
	int m_itemId = 02;
	int m_itemCost = 100;
	std::string m_itemDescription = "Heals poison effects from a Pokémon./n";

};

class PokeBall : public Item
{
public:
	std::string m_itemName = "PokeBall";
	int m_itemId = 03;
	int m_itemCost = 200;
	std::string m_itemDescription = "A capsule used for catching Pokémon with a standard catch rate./n";
};

class ParalyzHeal : public Item
{
public:
	std::string m_itemName = "ParalyzHeal";
	int m_itemId = 04;
	int m_itemCost = 200;
	std::string m_itemDescription = "Heals paralysis effects from a Pokémon./n";
};

class BurnHeal : public Item
{
public:
	std::string m_itemName = "BurnHeal";
	int m_itemId = 05;
	int m_itemCost = 250;
	std::string m_itemDescription = "Heals burn effects from a Pokémon./n";
};

#endif // !ITEMS_H
