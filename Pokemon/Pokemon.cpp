//Stephen
#include "Pokemon.h"

//default constructor / empty
Pokemon::Pokemon() {
	//m_pokedex = MISSINGNO;
	//m_nickname = "MISSINGNO";
	//m_level = 33;
	//m_status = OK;
	//m_baseHP = 33;
	//m_baseAtk = 136;
	//m_baseDef = 0;
	//m_baseSpd = 6;
	//m_baseSpe = 29;
	//emptyEV();
	//m_type1 = FLYING;
	//m_type2 = NORMAL;
	//m_catchRate = 29;
	//m_expYield = 1;
	//setStats();
	m_type2 = BLANK;
}

Pokemon::Pokemon(int pokemon, int level) {
	Pokemon();
	openPokemon(pokemon);
	openMoves(pokemon);
	m_level = level;
	m_status = OK;
	m_fainted = false;
	setIV();
	emptyEV();
	setEXP();
	setStats();
	setMoves(pokemon, m_level);
}

Pokemon::~Pokemon() {}

//void Pokemon::setPokemonStats(int pokedex){
//
//		m_pokedex = mP_pokedex[pokedex];
//		m_nickname = mP_name[pokedex];
//		//base stats
//		m_baseHP = mP_baseHP[pokedex];
//		m_baseAtk = mP_baseAtk[pokedex];
//		m_baseDef = mP_baseDef[pokedex];
//		m_baseSpd = getbaseSpd(pokedex);
//		m_baseSpe = mP_baseSpe[pokedex];
//
//		m_type1 = mP_type1[pokedex];
//		m_type1_str = mP_type1_str[pokedex];
//		m_type2 = mP_type2[pokedex];
//		m_type2_str = mP_type2_str[pokedex];
//		m_catchRate = mP_catchRate[pokedex];
//		m_expYield = mP_expYield[pokedex];
//		m_evolve = mP_evolve[pokedex];
//		m_kind = mP_kind[pokedex];
//		m_height = mP_height[pokedex];
//		m_weight = mP_weight[pokedex];
//		m_description = mP_description[pokedex];
//
//}

void Pokemon::openPokemon(int pokedex_num) {
	//Pokedex CSV: https://docs.google.com/spreadsheets/d/1J1R6JvNBhYi7kmQSRrePLh0hvVVZrVLmUItml668wBo/edit?usp=sharing
	std::ifstream src("../Debug/Assets/Pokedex.csv");
	if (!src.is_open()) {
		std::cout << "Could not open file: Pokedex.csv" << std::endl;
	}
	else {
		//Determines which row to fetch data from based on num_pokedex
		for (int k = 0; k < pokedex_num; k++) {
			src.ignore(500, '\n'); //ignore the first 500 characters, or until first \n. skips headers
		}

		src >> m_pokedex;
		src.ignore(1, ',');

		getline(src, m_nickname, ',');
		//base stats
		src >> m_baseHP;
		src.ignore(1, ',');
		src >> m_baseAtk;
		src.ignore(1, ',');
		src >> m_baseDef;
		src.ignore(1, ',');
		src >> m_baseSpd;
		src.ignore(1, ',');
		src >> m_baseSpe;
		src.ignore(1, ',');

		//types
		getline(src, m_type1_str, ',');
		m_type1 = typeConvert(m_type1_str);

		getline(src, m_type2_str, ',');
		if (m_type2_str != "") {
			m_type2 = typeConvert(m_type2_str);
		}

		//other
		src >> m_catchRate;
		src.ignore(1, ',');
		src >> m_expYield;
		src.ignore(1, ',');
		src >> m_expGroup;
		src.ignore(1, ',');
		src >> m_evolve;
		src.ignore(1, ',');
		getline(src, m_kind, ',');
		getline(src, m_height, ',');
		src >> m_weight;
		src.ignore(1, ',');
		getline(src, m_description, '\n');

		src.close();
	}

}

void Pokemon::openMoves(int move_id) {
	// CSV: https://docs.google.com/spreadsheets/d/1rtdeZ5ZnPfdBtJH66HlOrYkcqv8HtF1vYtElf6xY40M/edit?usp=sharing
	std::ifstream src("../Debug/Assets/learning_moves.csv");
	if (!src.is_open()) {
		std::cout << "Could not open file: learning_moves.csv" << std::endl;
	}
	else {
		for (int k = 0; k < move_id; k++) {
			src.ignore(500, '\n'); //ignore the first 500 characters, or until first \n. skips headers
		}

		src.ignore(20, ',');
		src.ignore(20, ',');

		src >> m_numMoves;
		src.ignore(1, ',');
		//Stores levels moves are learnt and moves learnt at level
		for (int k = 0; k < m_numMoves; k++) {
			src >> m_learnLevel[k];
			src.ignore(1, ',');
			src >> m_moveToLearn[k];
			src.ignore(1, ',');
		}

		src.close();
	}
}

void Pokemon::setIV() {
	m_IV_hp = 0;
	m_IV_atk = randomGen(0, 15);
	m_IV_def = randomGen(0, 15);
	m_IV_spd = randomGen(0, 15);
	m_IV_spe = randomGen(0, 15);

	//HP determined through other IV's
	if (m_IV_atk % 2 != 0) {
		m_IV_hp += 8;
	}
	if (m_IV_def % 2 != 0) {
		m_IV_hp += 4;
	}
	if (m_IV_spd % 2 != 0) {
		m_IV_hp += 2;
	}
	if (m_IV_spe % 2 != 0) {
		m_IV_hp += 1;
	}
}

void Pokemon::emptyEV() {
	m_EV_hp = 0;
	m_EV_atk = 0;
	m_EV_def = 0;
	m_EV_spd = 0;
	m_EV_spe = 0;
}

void Pokemon::setStats() {
	//The HP stat follows: HP = ((((Base + IV) * 2 + (sqrt(EV) / 4)) * Level ) / 100) + Level + 10.
	//All other stats follows : Stat = ((((Base + IV) * 2 + (sqrt(EV) / 4)) * Level ) / 100) + 5

	m_hp = int(((((m_baseHP + m_IV_hp) * 2 + (sqrt(m_EV_hp) / 4)) * m_level) / 100) + m_level + 10);
	m_maxHP = m_hp;
	m_atk = int(((((m_baseAtk + m_IV_atk) * 2 + (sqrt(m_EV_atk) / 4)) * m_level) / 100) + 5);
	m_def = int(((((m_baseDef + m_IV_def) * 2 + (sqrt(m_EV_def) / 4)) * m_level) / 100) + 5);
	m_spd = int(((((m_baseSpd + m_IV_spd) * 2 + (sqrt(m_EV_spd) / 4)) * m_level) / 100) + 5);
	m_spe = int(((((m_baseSpe + m_IV_spe) * 2 + (sqrt(m_EV_spe) / 4)) * m_level) / 100) + 5);
}

void Pokemon::setMoves(int pokemon, int level) {
	int k = 0;
	int moveCount = 0;
	//Count possible moves to learn
	do {
		moveCount++;
	} while (m_learnLevel[moveCount] <= level && m_learnLevel[moveCount] > 0);
	//Learn up to available moves
	if (moveCount <= 4) {
		do {
			move[k].populateMove(m_moveToLearn[k]);
			k++;
		} while (m_learnLevel[k] <= level);
		for (k; k < 4; k++) {
			move[k].populateMove(0);
		}
	}
	else {
		//Learn randomly if more than 4 moves
		for (k = 0; k < 4; k++) {
			move[k].populateMove(m_moveToLearn[randomGen(0, (moveCount - 1))]);
			//Make sure move isn't learnt already
			for (int j=0; j < k; j++)
			if (move[k].getMoveID() == move[j].getMoveID()) {
				k--;
			}
		}
	}
}

void Pokemon::setEXP() {
	switch (m_expGroup) {
	case SLOW:
		m_exp = int((5 * (pow(m_level, 3))) / 4);
		break;
	case MED_SLOW:
		m_exp = int((1.2 * (pow(m_level, 3))) - (15 * pow(m_level, 2)) + (100 * m_level) - 140);
		break;
	case MED_FAST:
		m_exp = int(pow(m_level, 3));
		break;
	case FAST:
		m_exp = int(4 * pow(m_level, 3)) / 5;
		break;
	}
}

void Pokemon::resetStatStages() {
	m_atkStage = 0;
	m_defStage = 0;
	m_spdStage = 0;
	m_speStage = 0;
	m_accStage = 100;
	m_evaStage = 100;
}

void Pokemon::displayMoves() {
	using namespace std;
	cout << "Move 1: " << move[0].getMoveName() << endl;
	cout << "Move 2: " << move[1].getMoveName() << endl;
	cout << "Move 3: " << move[2].getMoveName() << endl;
	cout << "Move 4: " << move[3].getMoveName() << endl << endl;
}

void Pokemon::displayStats() {
	using namespace std;

	cout << "Level: " << m_level << " " << m_nickname << endl;
	cout << "HP: " << m_hp << endl;
	cout << "Attack: " << m_atk << endl;
	cout << "Defence: " << m_def << endl;
	cout << "Speed: " << m_spd << endl;
	cout << "Special: " << m_spe << endl;
	cout << "Type: " << m_type1_str << ", " << m_type2_str << endl;
	cout << "Move 1: " << move[0].getMoveName() << endl;
	cout << "Move 2: " << move[1].getMoveName() << endl;
	cout << "Move 3: " << move[2].getMoveName() << endl;
	cout << "Move 4: " << move[3].getMoveName() << endl << endl;
}

void Pokemon::displayStats2() {
	using namespace std;

	cout << "Level: " << m_level << " " << m_nickname << endl;
	cout << "HP: " << m_hp << endl;
	cout << "Attack: " << m_atk << endl;
	cout << "Defence: " << m_def << endl;
	cout << "Speed: " << m_spd << endl;
	cout << "Special: " << m_spe << endl;
	cout << "Type: " << m_type1_str << ", " << m_type2_str << endl << endl;
}