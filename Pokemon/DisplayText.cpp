#include "DisplayText.h"

using namespace std;

TextScreen::TextScreen()
{
}

void TextScreen::Talk(string NPC){
	string Name;
	string Speech;
	bool Found = false;

	std::ifstream src("../Debug/Assets/pokemonblue_text.csv");
	if (!src.is_open()) {
		std::cout << "Couldn't open file: pokemonblue_text.csv" << std::endl;
	} 
	else {
		do {
			getline(src, Name, ',');
			if (NPC == Name) {
				getline(src, Speech, ',');
				Found = true;
			}
			else {
				src.ignore(500, '\n');
			}
		} while (!Found || src.eof());
	} 
	src.close();
}

void TextScreen::Update()
{
}
