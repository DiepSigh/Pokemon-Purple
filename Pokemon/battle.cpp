//Stephen
#include "battle.h"

battle::battle() {
	playerBound = false;
	aiBound = false;
	playerConfuse = false;
	aiConfuse = false;
	playerFlinch = false;
	aiFlinch = false;
	playerSeed = false;
	aiSeed=false;
	//7,90
	m_battleScreen = new battle(0,0, new Texture("battle_screen.png", 7,90, 162, 146));
	//m_battleScreen = new battle(0, 0, new AnimatedTexture("battle_screen.png", 0, 0, 500, 500, 1, 1, 0) new Texture("battle_screen.png", 0, 0, 162, 146));
	m_battleScreen->SetPosX(100);
	m_battleScreen->SetPosY(100);
}

battle::battle(int x, int y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	mPos.x = x;
	mPos.y = y;
	mTex = tex;
}

void battle::startBattle() {
	m_battleScreen->Render();
}

void battle::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

battle* battle::sInstance = nullptr;

battle*battle::Instance() {
	if (sInstance == nullptr) {
		sInstance = new battle();
	}

	return sInstance;
}

void battle::release() {
	delete sInstance;
	sInstance = nullptr;
}


void battle::fight(Pokemon &active, Pokemon &opposing) {
	battle();
	active.resetStatStages();
	opposing.resetStatStages();
	using namespace std;
	active.setSide(PLAYER);
	opposing.setSide(AI);
	std::cout << "Commence battle.\n";
	do {
		active.displayStats();
		opposing.displayStats();
		int input = 0;
		int playerMove = 0;
		std::cout << "Choose move 1-4;\n\n";
		std::cin >> input;
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
		int attacker = firstAttack(active, input-1, opposing, aiMove);
		if (!faintCheck(active, opposing)) {
			if (attacker == PLAYER) {
				secondAttack(opposing, active, aiMove);
			}
			else {
				secondAttack(active, opposing, input-1);
			}
		}
	} while (!faintCheck(active, opposing));
	if (active.getFainted()) {
		cout << active.getName() << " has fainted.";
	}
	else {
		cout << opposing.getFainted() << " has fainted.";
	}
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
			if (moveCount == 4) {
				done = true;
			}
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

int battle::firstAttack(Pokemon &active, int playerMove, Pokemon &opposing, int aiMove) {
	bool pFirst = false;
	aiFlinch = false;
	playerFlinch = false;
	int damage = 0;

	pFirst = playerFirst(active, playerMove, opposing, aiMove);
	if (pFirst) {
		//accuracy check
		if (!attackMissed(active.getMove(playerMove).getAcc(), active.getAccStage(), opposing.getEvaStage())) {
			//check if damaging move or status move
			if (active.getMove(playerMove).getCat() == STATUS) {
				//check if status effect or stat change
				if (active.getMove(playerMove).getEffect() > 0) {
					//check if volatile or non-volatile
					if (active.getMove(playerMove).getEffect() >= 7) {
						nvStatusChange(AI, active.getMove(playerMove).getEffect());
					}else{
						vStatusChange(opposing, active.getMove(playerMove).getEffect());
					}
				}else{
					statChange(active, opposing, active.getMove(playerMove).getMoveID());
				}

			}
			else {
				//player attacks
				damage = damageCalculation(active, opposing, playerMove);
				opposing.hurt(damage);
				//statChange(AI, active.getMove(playerMove).getMoveID());
				std::cout << active.getName() << " used " << active.getMove(playerMove).returnMove() << std::endl;
				std::cout << "It did " << damage << " damage!\n";
			}
		}else{
			//attack missed
			std::cout << "Attack missed.\n";
		}
	}
	else {
		//accuracy check
		if (!attackMissed(opposing.getMove(aiMove).getAcc(), opposing.getAccStage(), active.getEvaStage())) {
			//check if damaging move or status move
			if (opposing.getMove(aiMove).getCat() == STATUS) {
				//check if status effect or stat change
				if (opposing.getMove(aiMove).getEffect() > 0) {
					//check if volatile or non-volatile
					if (opposing.getMove(aiMove).getEffect() >= 7) {
						nvStatusChange(AI, opposing.getMove(aiMove).getEffect());
					}
					else {
						vStatusChange(active, opposing.getMove(aiMove).getEffect());
					}
				}
				else {
					statChange(opposing, active, opposing.getMove(aiMove).getMoveID());
				}

			}
			else {
				//AI attacks
				damage = damageCalculation(opposing, active, aiMove);
				active.hurt(damage);
				std::cout << opposing.getName() << " used " << opposing.getMove(aiMove).returnMove() << std::endl;
				std::cout << "It did " << damage << " damage!\n";
			}
		}
		else {
			//attack missed
			std::cout << "Attack missed.\n";
			
		}
	}

	if (pFirst) {
		return PLAYER;
	}
	else {
		return AI;
	}

}

void battle::secondAttack(Pokemon &attacking, Pokemon &defending, int move) {
	int damage = 0;

		//accuracy check
		if (!attackMissed(attacking.getMove(move).getAcc(), attacking.getAccStage(), defending.getEvaStage())) {
			//check if damaging move or status move
			if (attacking.getMove(move).getCat() == STATUS) {
				//check if status effect or stat change
				if (attacking.getMove(move).getEffect() > 0) {
					//check if volatile or non-volatile
					if (attacking.getMove(move).getEffect() >= 7) {
						nvStatusChange(attacking.getSide(), attacking.getMove(move).getEffect());
					}
					else {
						vStatusChange(attacking, defending.getMove(move).getEffect());
					}
				}
				else {
					statChange(attacking, defending, attacking.getMove(move).getMoveID());
				}

			}
			else {
				//AI attacks
				damage = damageCalculation(attacking, defending, move);
				attacking.hurt(damage);
				std::cout << attacking.getName() << " used " << attacking.getMove(move).returnMove() << std::endl;
				std::cout << "It did " << damage << " damage!\n";
			}
		}
		else {
			//attack missed
			std::cout << "Attack missed.\n";

		}
}

bool battle::playerFirst(Pokemon &active, int playerMove, Pokemon &opposing, int aiMove) {
	//Compare priority
	if (active.getMove(playerMove).getPriority() > opposing.getMove(aiMove).getPriority()) {
		return true;
	}
	//Compare speed
	else if ((active.getSpd() * stageConversion(active.getSpdStage())) > (opposing.getSpd() * stageConversion(opposing.getSpdStage()))) {
		return true;
	}
	//50/50 for same speed
	else {
		int rng = randomGen(1, 2);
		if (rng == 1) {
			return true;
		}
	}
	return false;
}

void battle::statusCheck(Pokemon &player, Pokemon &ai) {

}

bool battle::faintCheck(Pokemon &player, Pokemon &ai) {
	int fainted = false;
	if (player.getHP() <= 0) {
		player.fainted();
		fainted = true;
	}
	if (ai.getHP() <= 0) {
		ai.fainted();
		fainted = true;
	}
	return fainted;
}

void battle::nvStatusChange(int affected, int effect) {
	if (affected == AI) {
		switch (effect) {
		case BOUND:
			//to be completed
			break;
		case CONFUSE:
			if (!aiConfuse) {
				aiConfuse = true;
			}
			break;
		case FLINCH:
			aiFlinch = true;
			break;
		case LEECH:
			if (!aiSeed) {
				aiSeed = true;
			}
			break;
		}
	}
}

void battle::vStatusChange(Pokemon &affected, int effect) {
	//only occurs if Pokemon isn't already effected
	if (affected.getStatus() == 0) {
		switch (effect) {
		case PARALYSIS:
			affected.setStatus(PARALYZED);
			break;
		case POISON:
			affected.setStatus(POISONED);
			break;
		case BAD_POISON:
			affected.setStatus(BADLY_POISONED);
			break;
		case SLEEP:
			affected.setStatus(ASLEEP);
			break;
		}
	}else {
		//it has no effect or failed
	}
}

void battle::statChange(Pokemon &user, Pokemon &opposing, int move) {

	enum stat {att, def, spd, spe, acc, eva};
	int stat = 0;
	int change = 0;

	switch (move) {
		//attack
	case GROWL:
		stat = att;
		change -= 1;
		break;
	case MEDITATE: case SHARPEN: //case RAGE:
		stat = att;
		change += 1;
		break;
	case SWORDS_DANCE:
		stat = att;
		change += 2;
		break;
		//defence
	case LEER: case TAIL_WHIP:
		stat = def;
		change -= 1;
		break;
	case SCREECH:
		stat = def;
		change -= 2;
		break;
	case DEFENSE_CURL: case HARDEN: case WITHDRAW:
		stat = def;
		change += 1;
		break;
	case ACID_ARMOR: case BARRIER:
		stat = def;
		change += 2;
		break;
		//speed
	case STRING_SHOT:
		stat = spd;
		change -= 2;
		break;
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
		//accuracy
	case FLASH: case KINESIS: case SAND_ATTACK: case SMOKESCREEN:
		stat = acc;
		change -= 1;
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
	if (change > 0) {
		switch (stat) {
		case att:
			user.setAtkStage(change);
			break;
		case def:
			user.setDefStage(change);
			break;
		case spd:
			user.setSpdStage(change);
			break;
		case spe:
			user.setSpeStage(change);
			break;
		case acc:
			user.setAccStage(change);
			break;
		case eva:
			user.setEvaStage(change);
			break;
		}
	}
	else if (change < 0) {
		switch (stat) {
		case att:
			opposing.setAtkStage(change);
			break;
		case def:
			opposing.setDefStage(change);
			break;
		case spd:
			opposing.setSpdStage(change);
			break;
		case spe:
			opposing.setSpeStage(change);
			break;
		case acc:
			opposing.setAccStage(change);
			break;
		case eva:
			opposing.setEvaStage(change);
			break;
		}
	}
}

float battle::stageConversion(int stage) {
	switch (stage) {
	case -6:
		return 0.25;
	case -5:
		return 0.28;
	case -4:
		return 0.33;
	case -3:
		return 0.4;
	case -2:
		return 0.5;
	case -1:
		return 0.66;
	case 0:
		return 1;
	case 1:
		return 1.5;
	case 2:
		return 2;
	case 3:
		return 2.5;
	case 4:
		return 3;
	case 5:
		return 3.5;
	case 6:
		return 4;
	default: 
		return 1;
	}
}

bool battle::attackMissed(int baseAcc, int accuracy, int evasion) {
	if (baseAcc != 0) {
		float p = 1;

		p = (baseAcc * 0.01) * (stageConversion(accuracy) / stageConversion(evasion));
		if (p >= 1) {
			return false;
		}
		else {
			float rng = randomGen(0, 1);
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

int battle::damageCalculation(Pokemon &attacking, Pokemon &defending, int move) {
	// ((((((2*Level)/5) + 2) * Power * A/D) / 50) + 2) x Modifier
	double damage = 0;
	int moveType = attacking.getMove(move).getMoveType();
	int level = attacking.getLevel();
	//Critical Hit?
	bool crit = false;
	double t = attacking.getSpd() * 0.5;
	switch (move) {
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

	int power = attacking.getMove(move).getPower();

	int a = 1;
	int d = 1;
	if (attacking.getMove(move).getCat() == PHYSICAL) {
		a = attacking.getAtk() * (stageConversion(attacking.getAtkStage()));
		d = defending.getDef() * (stageConversion(defending.getDefStage()));
	}else if (attacking.getMove(move).getCat() == SPECIAL ) {
		a = attacking.getSpe() * (stageConversion(attacking.getSpeStage()));
		d = defending.getSpe() * (stageConversion(attacking.getSpeStage()));
	}
	//Building Modifier
	double random = randomGen(85, 100) * 0.01; //integer percentage 0.85 to 1.00
	float STAB = 1;
	if (attacking.getType1() == moveType || attacking.getType2() == moveType) {	STAB = 1.5; }

	//Type Effectiveness
	float type = 1;
	type *= typeEffectiveness(moveType, defending.getType1());
	if (defending.getType2() != BLANK) {
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
		break;
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
		break;
	case FLYING:
		switch (pokemon) {
		case POISON: case BUG: case GRASS:
			multiplier *= 2;
			break;
		case ROCK: case ELECTRIC:
			multiplier *= 0.5;
			break;
		}
		break;
	case POISON:
		switch (pokemon) {
		case BUG: case GRASS:
			multiplier *= 2;
			break;
		case POISON: case GROUND: case ROCK: case GHOST:
			multiplier *= 0.5;
			break;
		}
		break;
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
		break;
	case ROCK:
		switch (pokemon) {
		case FLYING: case BUG: case FIRE: case ICE:
			multiplier *= 2;
			break;
		case FIGHTING: case GROUND:
			multiplier *= 0.5;
			break;
		}
		break;
	case BUG:
		switch (pokemon) {
		case POISON: case GRASS: case PSYCHC:
			multiplier *= 2;
			break;
		case FIGHTING: case FLYING: case GHOST: case FIRE:
			multiplier *= 0.5;
			break;
		}
		break;
	case GHOST:
		switch (pokemon) {
		case GHOST:
			multiplier *= 2;
			break;
		case NORMAL: case PSYCHC:
			multiplier = 0;
			break;
		}
		break;
	case FIRE:
		switch (pokemon) {
		case BUG: case GRASS: case ICE:
			multiplier *= 2;
			break;
		case ROCK: case WATER: case FIRE: case DRAGON:
			multiplier *= 0.5;
			break;
		}
		break;
	case WATER:
		switch (pokemon) {
		case GROUND: case ROCK: case FIRE:
			multiplier *= 2;
			break;
		case WATER: case GRASS: case DRAGON:
			multiplier *= 0.5;
			break;
		}
		break;
	case GRASS:
		switch (pokemon) {
		case GROUND: case ROCK: case WATER:
			multiplier *= 2;
			break;
		case FLYING: case POISON: case BUG: case FIRE: case GRASS: case DRAGON:
			multiplier *= 0.5;
			break;
		}
		break;
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
		break;
	case PSYCHC:
		switch (pokemon) {
		case FIGHTING: case POISON:
			multiplier *= 2;
			break;
		case PSYCHC:
			multiplier *= 0.5;
			break;
		}
		break;
	case ICE:
		switch (pokemon) {
		case FLYING: case GROUND: case GRASS: case DRAGON:
			multiplier *= 2;
			break;
		case WATER: case ICE:
			multiplier *= 0.5;
			break;
		}
		break;
	case DRAGON:
		switch (pokemon) {
		case DRAGON:
			multiplier *= 2;
			break;
		}
	}

	return multiplier;
}