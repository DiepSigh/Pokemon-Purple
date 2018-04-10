#include "Dialouge.h"

Dialouge* Dialouge::sInstance = nullptr;


Dialouge* Dialouge::Instance() {
	if (sInstance == nullptr) {
		sInstance = new Dialouge();
	}
	return sInstance;
}

Dialouge::Dialouge() {
	textDisplay();
}

void Dialouge::textDisplay(){
	//DON'T TOUCH
	/*
	Opens CSV file, stores the data into a mutlidimension array of NPCtext
	Use NPCtext array to get strings of NPC dialouge 
	*/

	//This line opens th CSV file and checks for errors
	std::ifstream src("../Debug/Assets/pokemonblue_text.csv");
	if (!src.is_open()) {
		std::cout << "Couldn't open file: pokemonblue_text.csv" << std::endl;
	} 
	
	//two for loops to cycle the Rows(r) and Columns (c) to store string data into NPCtext
	for (int r = 0; r < 188; r++) {
		for (int c = 0; c < 27; c++) {
			getline(src, NPCtext[r][c], ',');
			std::cout << std::to_string(r) + ' ' + std::to_string(c) + ' ' + NPCtext[r][c] << std::endl;
		}
	}
	//Closes the CSV file
	src.close();
	
}

void Dialouge::Release() {
	delete sInstance;
	sInstance = nullptr;
}

Dialouge::~Dialouge()
{
}
