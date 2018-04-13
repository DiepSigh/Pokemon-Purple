#include "AudioManager.h"

AudioManager* AudioManager::sInstance = NULL;

AudioManager* AudioManager::Instance() {

	if (sInstance == NULL) {
		sInstance = new AudioManager();
	}

	return sInstance;
}

void AudioManager::Release() {
	
	delete sInstance;
	sInstance = NULL;

}

AudioManager::AudioManager() {

	mAssetMng = AssetManager::Instance();

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
	
		printf("Mixer Initialization Error: %\n", Mix_GetError());
	}
}

AudioManager::~AudioManager() {

	mAssetMng = NULL;
	Mix_Quit();
}

void AudioManager::PlayMusic(std::string filename, int loops) {
	
	Mix_PlayMusic(mAssetMng->GetMusic(filename), loops);

}

void AudioManager::PauseMusic() {
	
	if (Mix_PlayingMusic() != 0) {
		Mix_PauseMusic();
	}
}

void AudioManager::ResumeMusic() {

	if (Mix_PausedMusic() != 0) {
		Mix_ResumeMusic();
	}
}

void AudioManager::PlaySFX(std::string filename, int loops, int channel) {

	Mix_PlayChannel(channel, mAssetMng->GetSFX(filename), loops);
}

void AudioManager::StartGameSound() {
	PlayMusic("sounds/StartGameSound.wav");
}

void AudioManager::DialogWithOakSound() {
	PlayMusic("sounds/DialogWithOakSound.wav");
}

void AudioManager::PalletTownSound() {
	PlayMusic("sounds/PaletteTownTheme.wav");
}

void AudioManager::ReserchLabSound() {
	PlayMusic("sounds/ResearchLab.wav");
}

void AudioManager::RoadToViridianCitySound() {
	PlayMusic("sounds/RoadViridianCityFromPalette.wav");
}

void AudioManager::ViridianCitySound() {
	PlayMusic("sounds/ViridianCity.wav");
}

void AudioManager::PokemonCenterSound() {
	PlayMusic("sounds/PokemonCenter.wav");
}

void AudioManager::PokemonMartSound() {
	PlayMusic("sounds/PokemonMart.wav");
}
void AudioManager::BattleVsWildPokemonSound() {
	PlayMusic("sounds/BattleVsWildPokemon.wav");
}

void AudioManager::VictoryVsWildPokemon() {
	PlayMusic("sounds/VictoryVsWildPokemon.wav");
}


void AudioManager::BumpSFX() {
	PlaySFX("sounds/bump.wav", 0);
}

void AudioManager::ExitSFX() {
	PlaySFX("sounds/exit.wav", 0);
}