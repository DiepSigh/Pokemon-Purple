#include "PokeBase.h"
#include "moves.h"

PokeBase::PokeBase() {
	populatePokemon();
	//populateMoves();
	//populateLearningMoves();
}

PokeBase* PokeBase::sInstance = nullptr;

PokeBase*PokeBase::Instance() {
	if (sInstance == nullptr) {
		sInstance = new PokeBase();
	}

	return sInstance;
}

void PokeBase::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void PokeBase::populatePokemon() {
	//Pokedex CSV: https://docs.google.com/spreadsheets/d/1J1R6JvNBhYi7kmQSRrePLh0hvVVZrVLmUItml668wBo/edit?usp=sharing
	std::ifstream src("../Debug/Assets/csv/Pokedex.csv");
	if (!src.is_open()) {
		std::cout << "Could not open file: Pokedex.csv" << std::endl;
	}
	else {
		src.ignore(500, '\n'); //ignore the first 500 characters, or until first \n. skips headers

		for (int k = 0; k < mP_Pokemon; k++) {
			
			src >> mP_pokedex[k];
			src.ignore(1, ',');

			getline(src, mP_name[k], ',');
			//base stats
			src >> mP_baseHP[k];
			src.ignore(1, ',');
			src >> mP_baseAtk[k];
			src.ignore(1, ',');
			src >> mP_baseDef[k];
			src.ignore(1, ',');
			src >> mP_baseSpd[k];
			src.ignore(1, ',');
			src >> mP_baseSpe[k];
			src.ignore(1, ',');

			//types
			getline(src, mP_type1_str[k], ',');
			mP_type1[k] = typeConvert(mP_type1_str[k]);

			getline(src, mP_type2_str[k], ',');
			if (mP_type2_str[k] != "") {
				mP_type2[k] = typeConvert(mP_type2_str[k]);
			}

			//other
			src >> mP_catchRate[k];
			src.ignore(1, ',');
			src >> mP_expYield[k];
			src.ignore(1, ',');
			src >> mP_expGroup[k];
			src.ignore(1, ',');
			src >> mP_evolve[k];
			src.ignore(1, ',');
			getline(src, mP_kind[k], ',');
			getline(src, mP_height[k], ',');
			src >> mP_weight[k];
			src.ignore(1, ',');
			getline(src, mP_description[k], '\n');
		}

		src.close();
	}
}

//void PokeBase::populateMoves() {
//	//CSV: https://docs.google.com/spreadsheets/d/1J1R6JvNBhYi7kmQSRrePLh0hvVVZrVLmUItml668wBo/edit?usp=sharing
//	Move();
//	std::ifstream src("../Debug/Assets/csv/moves.csv");
//
//	if (!src.is_open()) {
//		std::cout << "Could not open file moves.csv.";
//	}
//	else {
//		src.ignore(500, '\n'); //ignore the first 500 characters, or until first \n. skips headers
//		for (int k = 0; k < mP_Moves; k++) {
//
//			src >> mP_moveID[k];
//			src.ignore(1, ',');
//
//			getline(src, mP_moveName[k], ',');
//			getline(src, mP_moveType_str[k], ',');
//			mP_moveType[k] = typeConvert(mP_moveType_str[k]);
//
//			src >> mP_moveCat[k];
//			src.ignore(1, ',');
//			src >> mP_movePower[k];
//			src.ignore(1, ',');
//			src >> mP_moveAcc[k];
//			src.ignore(1, ',');
//			src >> mP_movePPMax[k];
//			src.ignore(1, ',');
//			src >> mP_moveEffect[k];
//			src.ignore(1, ',');
//			src >> mP_moveChance[k];
//			src.ignore(1, ',');
//			src >> mP_movePriority[k];
//
//		}
//		
//		src.close();
//	}
//}
//
//void PokeBase::populateLearningMoves() {
//	// CSV: https://docs.google.com/spreadsheets/d/1rtdeZ5ZnPfdBtJH66HlOrYkcqv8HtF1vYtElf6xY40M/edit?usp=sharing
//	std::ifstream src("../Debug/Assets/csv/learning_moves.csv");
//	if (!src.is_open()) {
//		std::cout << "Could not open file: learning_moves.csv" << std::endl;
//	}
//	else {
//		src.ignore(500, '\n'); //ignore the first 500 characters, or until first \n. skips headers
//		for (int j = 0; j < mP_Pokemon; j++) {
//
//			src.ignore(20, ',');
//			src.ignore(20, ',');
//
//			src >> mP_numMoves[j];
//			src.ignore(1, ',');
//			//Stores levels moves are learnt and moves learnt at level
//			for (int k = 0; k < mP_numMoves[j]; k++) {
//				src >> mP_learnLevel[j][k];
//				src.ignore(1, ',');
//				src >> mP_moveToLearn[j][k];
//				src.ignore(1, ',');
//			}
//		}
//		src.close();
//	}
//}