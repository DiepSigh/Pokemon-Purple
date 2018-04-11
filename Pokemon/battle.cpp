//Stephen
#include "battle.h"

battle::battle() {
	//7,90, 162, 146
	//m_battleScreen = new battle(0,0, new Texture("battle_screen.png", 28, 370, 648, 600));
	//m_battleScreen = new battle(0, 0, new AnimatedTexture("battle_screen.png", 28, 360, 162*4, 152*4, 1, 1.0f ,AnimatedTexture::HORIZONTAL));
	m_battleScreen = new battle(0, 0, new Texture("battle/battle_screen.png", 28 + 648 + 4, 370, 648, 600));
	//+648+4
	m_battleScreen->SetPosX(80);
	m_battleScreen->SetPosY(0);
}

battle::battle(int x, int y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	mPos.x = x;
	mPos.y = y;
	mTex = tex;
}

void battle::startBattle(Pokemon &one, Pokemon &two) {
	m_battleScreen->Render();
	two.getFront()->Render();
	one.getBack()->Render();
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

void battle::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void battle::fight(Pokemon &active, Pokemon &opposing) {
	battle();
	active.resetStatStages();
	opposing.resetStatStages();
	resetStates(active, opposing);
	using namespace std;

	std::cout << "Commence battle.\n";
	do {
		active.displayStats();
		opposing.displayStats2();
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
				attack(opposing, active, aiMove);
			}else {
				attack(active, opposing, input-1);
			}
		}
		statusCheck2(active, opposing);
		statusCheck2(opposing, active);
	} while (!faintCheck(active, opposing));
	if (active.getFainted()) {
		cout << active.getName() << " has fainted.";
	}
	else {
		cout << opposing.getFainted() << " has fainted.";
	}
	//set to normal poison after battle ends
	if (active.getStatus() == BADLY_POISONED) {
		active.setStatus(POISONED);
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
		}else {
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
	active.setFlinched(false);
	opposing.setFlinched(false);

	pFirst = playerFirst(active, playerMove, opposing, aiMove);
	if (pFirst) {
		attack(active, opposing, playerMove);
	}else {
		attack(opposing, active, aiMove);
	}

	if (pFirst) {
		return PLAYER;
	}else {
		return AI;
	}

}

void battle::attack(Pokemon &attacking, Pokemon &defending, int move) {
	m_message = "";
	if (statusCheck1(attacking)) {
		double damage = 0;
		Move moveUsed = attacking.getMove(move);
		//accuracy check
		if (!attackMissed(moveUsed.getAcc(), attacking.getAccStage(), defending.getEvaStage())) {
			//check if damaging move or status move
			if (moveUsed.getCat() == STATUS) {
				//check if status effect or stat change
				if (moveUsed.getEffect() > 0) {
					//check if volatile or non-volatile
					if (moveUsed.getEffect() >= BOUND) {
						vStatusChange(defending, moveUsed.getEffect());
					}
					else {
						nvStatusChange(defending, moveUsed.getEffect());
					}
				}
				else {
					statChange(attacking, defending, moveUsed.getMoveID());
				}

			}
			else {
				//player attacks
				damage = damageCalculation(attacking, defending, move);
				//damage is halved if attacking pokemon is burned and uses a physical move.
				if (moveUsed.getCat() == PHYSICAL && attacking.getStatus() == BURNED) {
					damage *= 0.5;
				}
				defending.hurt(damage);
				//chance to inflict status
				chanceState(attacking, defending, moveUsed.getMoveID(), moveUsed.getEffect(), moveUsed.getChance());
			}
		}
		else {
			//attack missed
			m_message += "Attack missed.\n";
		}
		std::cout << attacking.getName() << " used " << moveUsed.getMoveName() << std::endl;
		//if (damage != 0) {
		//	std::cout << "It did " << damage << " damage!\n";
		//}
	}
	std::cout << m_message;
}

bool battle::playerFirst(Pokemon &active, int playerMove, Pokemon &opposing, int aiMove) {
	//Compare priority
	if (active.getMove(playerMove).getPriority() > opposing.getMove(aiMove).getPriority()) {
		return true;
	}
	else {
		//Compare speed
		int activeSpeed = active.getSpd() * stageConversion(active.getSpdStage());
		int opposingSpeed = opposing.getSpd() * stageConversion(opposing.getSpdStage());
		if (active.getStatus() == PARALYZED) {
			activeSpeed *= 0.25;
		}
		if (opposing.getStatus() == PARALYZED) {
			opposingSpeed *= 0.25;
		}
		if (activeSpeed > opposingSpeed) {
			return true;
		}
		//50/50 for same speed
		else if (activeSpeed == opposingSpeed) {
			int rng = randomGen(1, 2);
			if (rng == 1) {
				return true;
			}
		}
		return false;
	}

}

bool battle::statusCheck1(Pokemon &pokemon) {
	bool attack = true;
	//BOUND
	if (pokemon.getBounded()) {
		//takes 1/16 of max hp as damage
		pokemon.hurt(pokemon.getMaxHP() * 0.0625);
		m_message = "The attacks continues.\n";
		m_boundCount++;
		attack = false;
		if (m_boundCount <= 3) {
			//37.5% chance of lasting at turn 2 and 3
			if (0.375 < randomGen(0, 100) * 0.01) {
				pokemon.setBounded(false);
			}
		}else if (m_boundCount <= 5) {
			//12.5% chance of lasting at turn 4 and 5
			if (0.125 < randomGen(0, 100) * 0.01) {
				pokemon.setBounded(false);
			}
		}else{
			pokemon.setBounded(false);
		}
	}
	else {
		switch (pokemon.getStatus()) {
		case FROZEN:
			m_message = pokemon.getName() + " is frozen solid.\n";
			attack = false;
			break;
		case ASLEEP:
			//wakes up after 1-7 turns
			if (pokemon.getSleepCount() > randomGen(1, 7)) {
				pokemon.awake();
				m_message = pokemon.getName() + " woke up.\n";
			}else {
				m_message = pokemon.getName() + " is fast asleep.\n";
				pokemon.asleep();
				attack = false;
			}
			break;
		default:
			//CONFUSED
			if (pokemon.getConfused()) {
				//confused for 1-4 turns
				if (pokemon.getConfusedCount() > randomGen(1, 4)) {
					pokemon.resetConfused();
					m_message = pokemon.getName() + " is no longer confused.\n";
				}else {
					m_message = pokemon.getName() + " is confused.\n";
					pokemon.confused();
					//50% chance of hitting self with 40 power typeless physical
					if (randomGen(1, 2) == 1) {
						int damage = damageCalculation(pokemon, pokemon, CONFUSED);
						pokemon.hurt(damage);
						m_message += "It hurt itself in confusion.\n";
						attack = false;
					}
				}
			}
			//PARALYZED
			if (pokemon.getStatus() == PARALYZED) {
				if (0.25 < randomGen(0, 100) * 0.01) {
					m_message = pokemon.getName() + " cannot move.\n";
					attack = false;
				}
			}
		}
	}
	return attack;
}

void battle::statusCheck2(Pokemon &pokemon, Pokemon &other) {
	m_message = "";

	switch (pokemon.getStatus()) {
	case BURN:
		//takes 1/16 of max hp as damage
		pokemon.hurt(pokemon.getMaxHP() * 0.0625);
		m_message += pokemon.getName() + " is hurt by burn.\n";
		break;
	case POISONED:
		pokemon.hurt(pokemon.getMaxHP() * 0.0625);
		m_message += pokemon.getName() + " is hurt by poison.\n";
		break;
	case BADLY_POISONED:
		//adds 1/16 of max hp as damage every turn
		pokemon.hurt((pokemon.getMaxHP() * 0.0625) * pokemon.getPoisonCount());
		m_message += pokemon.getName() + " is hurt by poison.\n";
		pokemon.poison();
		break;
	}
	if (pokemon.getSeeded()) {
		int drain = pokemon.getMaxHP() * 0.0625;
		pokemon.hurt(drain);
		other.heal(drain);
		m_message += pokemon.getName() + " got its HP sapped.\n";
	}

	std::cout << m_message;
}

bool battle::faintCheck(Pokemon &player, Pokemon &ai) {
	int fainted = false;
	if (player.getFainted()) {
		fainted = true;
	}
	if (ai.getFainted()) {
		fainted = true;
	}
	return fainted;
}

void battle::resetStates(Pokemon &player, Pokemon &ai) {
	player.setBounded(false);
	player.setConfused(false);
	player.setFlinched(false);
	player.setSeeded(false);
	player.awake();
	player.cured();
	player.resetConfused();
	ai.setBounded(false);
	ai.setConfused(false);
	ai.setFlinched(false);
	ai.setSeeded(false);
	ai.awake();
	ai.cured();
	ai.resetConfused();
}

void battle::chanceState(Pokemon &attacking, Pokemon &defending, int move, int effect, int chance) {
	if (chance > 0) {
		if (chance >= randomGen(1, 100)) {
			nvStatusChange(defending, effect);
			vStatusChange(defending, effect);
			statChange(attacking, defending, move);
		}
	}
}

void battle::vStatusChange(Pokemon &affected, int effect) {
	switch (effect) {
	case BOUND:
		affected.setBounded(true);
		m_boundCount=1;
		break;
	case CONFUSE:
		if (!affected.getConfused()) {
			affected.setConfused(true);
			m_message = affected.getName() + " is confused.\n";
		}
		break;
	case FLINCH:
		affected.setFlinched(true);
		break;
	case LEECH:
		if (!affected.getSeeded()) {
			affected.setSeeded(true);
			m_message = affected.getName() + " is seeded.\n";
		}
		break;
	}
}

void battle::nvStatusChange(Pokemon &affected, int effect) {
	//only occurs if Pokemon isn't already affected
	if (affected.getStatus() == 0) {
		switch (effect) {
		case PARALYSIS:
			affected.setStatus(PARALYZED);
			m_message = affected.getName() + " has been paralyzed.\n";
			break;
		case POISON:
			affected.setStatus(POISONED);
			m_message = affected.getName() + " has been poisoned.\n";
			break;
		case BAD_POISON:
			affected.setStatus(BADLY_POISONED);
			m_message = affected.getName() + " has been badly poisoned.\n";
			break;
		case SLEEP:
			affected.setStatus(ASLEEP);
			m_message = affected.getName() + " fell asleep.\n";
			break;
		}
	}else {
		//if a status category move, message = it failed
	}
}

void battle::statChange(Pokemon &user, Pokemon &opposing, int move) {

	enum stat {att, def, spd, spe, acc, eva};
	int stat = 0;
	int change = 0;

	switch (move) {
		//attack
	case GROWL: case AURORA_BEAM:
		stat = att;
		change -= 1;
		break;
	case MEDITATE: case SHARPEN: case RAGE:
		stat = att;
		change += 1;
		break;
	case SWORDS_DANCE:
		stat = att;
		change += 2;
		break;
		//defence
	case LEER: case TAIL_WHIP: case ACID:
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
	case BUBBLE: case BUBBLE_BEAM: case CONSTRICT:
		stat = spd;
		change -= 1;
		break;
	case STRING_SHOT:
		stat = spd;
		change -= 2;
		break;
	case AGILITY:
		stat = spd;
		change += 2;
		break;
		//special
	case PSYCHIC:
		stat = spe;
		change -= 1;
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
		m_message += user.getName() + "'s ";
		switch (stat) {
		case att:
			user.setAtkStage(change);
			m_message += "attack rose.\n";
			break;
		case def:
			user.setDefStage(change);
			m_message += "defense rose.\n";
			break;
		case spd:
			user.setSpdStage(change);
			m_message += "speed rose.\n";
			break;
		case spe:
			user.setSpeStage(change);
			m_message += "special rose.\n";
			break;
		case acc:
			user.setAccStage(change);
			m_message += "accuracy rose.\n";
			break;
		case eva:
			user.setEvaStage(change);
			m_message += "evasion rose.\n";
			break;
		}
	}
	else if (change < 0) {
		m_message += opposing.getName() + "'s ";
		switch (stat) {
		case att:
			opposing.setAtkStage(change);
			m_message += "attack fell.\n";
			break;
		case def:
			opposing.setDefStage(change);
			m_message += "defense fell.\n";
			break;
		case spd:
			opposing.setSpdStage(change);
			m_message += "speed fell.\n";
			break;
		case spe:
			opposing.setSpeStage(change);
			m_message += "special fell.\n";
			break;
		case acc:
			opposing.setAccStage(change);
			m_message += "accuracy fell.\n";
			break;
		case eva:
			opposing.setEvaStage(change);
			m_message += "evasion fell.\n";
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
	//skip accuracy check if baseAcc is 0.
	if (baseAcc != 0) {
		float p = 1;
		//change baseAcc to percentage. change accuracy and evasion based on stages
		p = float((baseAcc * 0.01) * (stageConversion(accuracy) / stageConversion(evasion)));
		// p = baseAcc * accuracy / evasion
		// if p is 100%, return false/attack hits
		if (p >= 1) {
			return false;
		}
		else {
			int rng = randomGen(0, 100);
			if (p > rng*0.01) {
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
	//confused hit doesn't crit
	if (move != CONFUSED) {
		double t = attacking.getBaseSpd() * 0.5;
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
	}
	int power = attacking.getMove(move).getPower();

	int a = 1;
	int d = 1;
	//get appropriate stats according to category of move
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
	//Build damage
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

	if (multiplier == 2) {
		m_message += "It was super effective.\n";
	}
	else if (multiplier == 0.5) {
		m_message += "it wasn't very effective...\n";
	}
	else if (multiplier == 0) {
		m_message += "It had no effect.\n";
	}

	return multiplier;
}