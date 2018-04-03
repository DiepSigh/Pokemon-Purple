#include "battle.h"

battle::battle() {
	accPlayer = 100;
	accAI = 100;
	evaPlayer = 100;
	evaAI = 100;
}

void battle::fight(Pokemon &active, Pokemon &opposing) {

	int input = 0;
	int playerMove = 0;
	
	switch (input) {
	case 0:
		//playerMove = active.getMove(input).getMoveID();
		break;
	case 1:
		//playerMove = active.getMove(input).getMoveID();
		break;
	case 2:
		//playerMove = active.getMove(input).getMoveID();
		break;
	case 3:
		//playerMove = active.getMove(input).getMoveID();
		break;
	}
	
	int aiMove = AIChoice(opposing);
	firstAttack(active, input, opposing, aiMove);

}

int battle::AIChoice(Pokemon &ai) {
	int move = 0;
	int moveCount = 1;
	int k = 1;
	bool done = false;
	do {
		//if move is not empty
		if (ai.getMove(k).getMoveID() != 0) {
			moveCount++;
		}
		else {
			done = true;
		}
		k++;
	} while (!done);

	//random move to use
	move = randomGen(0, moveCount-1);
	return move;
}

void battle::firstAttack(Pokemon &active, int playerMove, Pokemon &opposing, int aiMove) {
	bool playerFirst = false;
	//Compare priority
	if (active.getMove(playerMove).getPriority() > opposing.getMove(aiMove).getPriority()) {
		playerFirst = true;
	}
	//Compare speed
	else if (active.getSpd() > opposing.getSpd()) {
		playerFirst = true;
	}
	//50/50 for same speed
	else if (active.getSpd() == opposing.getSpd()) {
		int rng = randomGen(1, 2);
		if (rng == 1) {
			playerFirst = true;
		}
	}

	if (playerFirst) {
		//accuracy check
		if (!attackMissed(active.getMove(playerMove).getAcc(), accPlayer, evaAI)) {
			//check if damaging move or status move
			if (active.getMove(playerMove).getCat() == STATUS) {
				//check if status effect or stat change
				if (active.getMove(playerMove).getEffect() > 0) {
					
				}else{
					statChange(PLAYER, active.getMove(playerMove).getMoveID());
				}
			}
			//player attacks
		}
	}
	else {
		//ai attacks
	}
}

void battle::statChange(int user, int move) {

	enum stat {att, def, spd, spe, eva};
	int stat = 0;
	int change = 0;

	switch (move) {
		//attack 
	case MEDITATE: case SHARPEN: //case RAGE:
		stat = att;
		change += 1;
		break;
	case SWORDS_DANCE:
		stat = att;
		change += 2;
		break;
		//defence
	case DEFENSE_CURL: case HARDEN: case WITHDRAW:
		stat = def;
		change += 1;
		break;
	case ACID_ARMOR: case BARRIER:
		stat = def;
		change += 2;
		break;
		//speed
	case AGILITY:
		stat = spd;
		change += 2;
		break;
		//special 
	case GROWTH:
		stat = spe;
		change += 1;
		break;
	case AMNESIA:
		stat = spe;
		change += 2;
		break;
		//evasion
	case DOUBLE_TEAM:
		stat = eva;
		change += 1;
		break;
	case MINIMIZE:
		stat = eva;
		change += 2;
		break;
	}
	if (user == PLAYER) {
		switch (stat) {
		case att:
			attPlayer += change;
			break;
		case def:
			defPlayer += change;
			break;
		case spd:
			spdPlayer += change;
			break;
		case spe:
			spePlayer += change;
			break;
		case eva:
			evaPlayer += change;
			break;
		}
	}
	else if (user == AI) {
		switch (stat) {
		case att:
			attAI += change;
			break;
		case def:
			defAI += change;
			break;
		case spd:
			spdAI += change;
			break;
		case spe:
			speAI += change;
			break;
		case eva:
			evaAI += change;
			break;
		}
	}
}

bool battle::attackMissed(int baseAcc, int accuracy, int evasion) {
	if (baseAcc != 0) {
		float p = 100;

		p = baseAcc * (accuracy / evasion);
		if (p >= 100) {
			return false;
		}
		else {
			int rng = randomGen(0, 100);
			if (p > rng) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

int battle::damageCalculation(Pokemon &attacking, Pokemon &defending, int num_move) {
	// ((((((2*Level)/5) + 2) * Power * A/D) / 50) + 2) x Modifier
	double damage = 0;
	int moveType = attacking.getMove(num_move).getMoveType();
	int level = attacking.getLevel();
	//Critical Hit?
	bool crit = false;
	double t = attacking.getSpe() * 0.5;
	switch (num_move) {
		//high crit rate
	case CRABHAMMER: case KARATE_CHOP: case RAZOR_LEAF: case SLASH:
		t *= 8;
		if (t > 255) {
			t = 255;
		}
	default:
		if (randomGen(0, 255) < t) {
			crit = true;
			level *= 2;
		}
	}

	int power = attacking.getMove(num_move).getPower();

	int a = 0;
	int d = 0;
	if (attacking.getMove(num_move).getCat() == PHYSICAL) {
		a = attacking.getAtk();
		d = defending.getDef();
	}else if (attacking.getMove(num_move).getCat() == SPECIAL ) {
		a = attacking.getSpe();
		d = defending.getSpe();
	}
	//Building Modifier
	double random = randomGen(85, 100) * 0.01; //integer percentage 0.85 to 1.00
	float STAB = 1;
	if (attacking.getType1() == moveType || attacking.getType2() == moveType) {	STAB = 1.5; }

	//Type Effectiveness
	float type = 1;
	type *= typeEffectiveness(moveType, defending.getType1());
	if (defending.getType2() != 0) {
		type *= typeEffectiveness(moveType, defending.getType2());;
	}

	double modifier = random * STAB * type;
	damage = ((((((2 * level) / 5) + 2) * power * a/d) / 50) + 2) * modifier;
	return int(damage);
}

float battle::typeEffectiveness(int move, int pokemon) {
	float multiplier = 1;
	switch (move) {
	case NORMAL:
		switch (pokemon) {
		case ROCK:
			multiplier -= 0.5;
			break;
		case GHOST:
			multiplier = 0;
			break;
		}
	case FIGHTING:
		switch (pokemon) {
		case NORMAL: case ROCK: case ICE:
			multiplier *= 2;
			break;
		case FLYING: case POISON: case BUG: case PSYCHC:
			multiplier *= 0.5;
			break;
		case GHOST:
			multiplier = 0;
			break;
		}
	case FLYING:
		switch (pokemon) {
		case POISON: case BUG: case GRASS:
			multiplier *= 2;
			break;
		case ROCK: case ELECTRIC:
			multiplier *= 0.5;
			break;
		}
	case POISON:
		switch (pokemon) {
		case BUG: case GRASS:
			multiplier *= 2;
			break;
		case POISON: case GROUND: case ROCK: case GHOST:
			multiplier *= 0.5;
			break;
		}
	case GROUND:
		switch (pokemon) {
		case POISON: case ROCK: case FIRE: case ELECTRIC:
			multiplier *= 2;
			break;
		case BUG: case GRASS:
			multiplier *= 0.5;
			break;
		case FLYING:
			multiplier = 0;
			break;
		}
	case ROCK:
		switch (pokemon) {
		case FLYING: case BUG: case FIRE: case ICE:
			multiplier *= 2;
			break;
		case FIGHTING: case GROUND:
			multiplier *= 0.5;
			break;
		}
	case BUG:
		switch (pokemon) {
		case POISON: case GRASS: case PSYCHC:
			multiplier *= 2;
			break;
		case FIGHTING: case FLYING: case GHOST: case FIRE:
			multiplier *= 0.5;
			break;
		}
	case GHOST:
		switch (pokemon) {
		case GHOST:
			multiplier *= 2;
			break;
		case NORMAL: case PSYCHC:
			multiplier = 0;
			break;
		}
	case FIRE:
		switch (pokemon) {
		case BUG: case GRASS: case ICE:
			multiplier *= 2;
			break;
		case ROCK: case WATER: case FIRE: case DRAGON:
			multiplier *= 0.5;
			break;
		}
	case WATER:
		switch (pokemon) {
		case GROUND: case ROCK: case FIRE:
			multiplier *= 2;
			break;
		case WATER: case GRASS: case DRAGON:
			multiplier *= 0.5;
			break;
		}
	case GRASS:
		switch (pokemon) {
		case GROUND: case ROCK: case WATER:
			multiplier *= 2;
			break;
		case FLYING: case POISON: case BUG: case FIRE: case GRASS: case DRAGON:
			multiplier *= 0.5;
			break;
		}
		case ELECTRIC:
			switch (pokemon) {
			case FLYING: case WATER:
				multiplier *= 2;
				break;
			case GRASS: case ELECTRIC: case DRAGON:
				multiplier *= 0.5;
				break;
			case GROUND:
				multiplier = 0;
				break;
			}
		case PSYCHC:
			switch (pokemon) {
			case FIGHTING: case POISON:
				multiplier *= 2;
				break;
			case PSYCHC:
				multiplier *= 0.5;
				break;
			}
		case ICE:
			switch (pokemon) {
			case FLYING: case GROUND: case GRASS: case DRAGON:
				multiplier *= 2;
				break;
			case WATER: case ICE:
				multiplier *= 0.5;
				break;
			}
		case DRAGON:
			switch (pokemon) {
			case DRAGON:
				multiplier *= 2;
				break;
			}
	}

	return multiplier;
}