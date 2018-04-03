#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H

#include "assetManager.h"

class AudioManager {

private:
	static AudioManager* sInstance;
	AssetManager* mAssetMng;

public:

	static AudioManager* Instance();
	static void Release();

	void PlayMusic(std::string filename, int loops = -1);
	void PauseMusic();
	void ResumeMusic();

	void PlaySFX(std::string filename, int loops = 0, int channel = 0);

	void PalletTownSound();
	void RoadToViridianCitySound();
	void ViridianCitySound();

private:

	AudioManager();
	~AudioManager();

};



#endif // !_AUDIOMANAGER_H

