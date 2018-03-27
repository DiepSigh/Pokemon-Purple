#include "moves.h"

#include <iostream>
#include <fstream>
#include <string>

Move::Move() {
	m_moveID = 0;
	m_moveName = "------";
	m_moveType = 0;
	m_moveType_str = "";
	m_moveCat = 0;
	m_movePower = 0;		
	m_moveAcc = 0;			
	m_movePPMax = 0;
	m_moveEffect = 0;		
	m_moveChance = 0;		
	m_movePriority = 0;
	m_movePPCurrent = 0;
}

const void Move::getMove(int move_index) {
	//CSV: https://docs.google.com/spreadsheets/d/1J1R6JvNBhYi7kmQSRrePLh0hvVVZrVLmUItml668wBo/edit?usp=sharing
	std::ifstream src("moves.csv");

	if (!src.is_open()) {
		std::cout << "Could not open file.";
	}

	else {
		//Determines which row to fetch data from based on move_index
		for (int k = 0; k < move_index; k++) {
			src.ignore(500, '\n'); //ignore the first 500 characters, or until first \n. skips headers
		}

		src >> m_moveID;
		src.ignore(1, ',');

		getline(src, m_moveName, ',');
		getline(src, m_moveType_str, ',');
		m_moveType = typeConvert(m_moveType_str);

		src >> m_moveCat;
		src.ignore(1, ',');
		src >> m_movePower;
		src.ignore(1, ',');
		src >> m_moveAcc;
		src.ignore(1, ',');
		src >> m_movePPMax;
		m_movePPCurrent = m_movePPMax;
		src.ignore(1, ',');
		src >> m_moveEffect;
		src.ignore(1, ',');
		src >> m_moveChance;
		src.ignore(1, ',');
		src >> m_movePriority;
		
		src.close();
	}
}

int Move::typeConvert(std::string t) {
	//enum pokemon_type { NORMAL=0, FIGHTING=1, FLYING=2, POISON=3, GROUND=4, ROCK=5, BUG=7, GHOST=8,
	//BLANK=9, FIRE=14, WATER=15, GRASS=16, ELECTRIC=17, PSYCHIC=18, ICE=19, DRAGON=20 };
	if (t == "NORMAL") {
		return NORMAL;
	}else if (t == "FIGHTING") {
		return FIGHTING;
	}else if (t == "FLYING") {
		return FLYING;
	}else if (t == "POISON") {
		return POISON;
	}else if (t == "GROUND") {
		return GROUND;
	}else if (t == "ROCK") {
		return ROCK;
	}else if (t == "BUG") {
		return BUG;
	}else if (t == "GHOST") {
		return GHOST;
	}else if (t == "FIRE") {
		return FIRE;
	}else if (t == "WATER") {
		return WATER;
	}else if (t == "GRASS") {
		return GRASS;
	}else if (t == "ELECTRIC") {
		return ELECTRIC;
	}else if (t == "PSYCHIC") {
		return PSYCHIC;
	}else if (t == "ICE") {
		return ICE;
	}else if (t == "DRAGON") {
		return DRAGON;
	}
}