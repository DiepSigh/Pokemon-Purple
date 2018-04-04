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

void AudioManager::GameMenuSound() {
	//PlayMusic();
}

void AudioManager::DialogWithOakSound() {
	//PlayMusic();
}

void AudioManager::PalletTownSound() {
	PlayMusic("Palette_Town_Theme.wav", 0);
}

void AudioManager::ReserchLabSound() {
	//PlayMusic();
}

void AudioManager::RoadToViridianCitySound() {
	PlayMusic("Road_Viridian_City_From_Palette.wav", 0);
}

void AudioManager::ViridianCitySound() {
	//PlayMusic();
}