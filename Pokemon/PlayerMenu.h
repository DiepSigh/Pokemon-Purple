#include "menu.h"

class PlayerMenu : public Menu {
public:
	PlayerMenu();
	PlayerMenu(float, float, Texture*);
	~PlayerMenu();

	static PlayerMenu* sInstance;
	static PlayerMenu* Instance();

	PlayerMenu* MenuP;
	PlayerMenu* Name;
	PlayerMenu* PlayerName;
	PlayerMenu* Money;
	PlayerMenu* PlayerMoney;
	PlayerMenu* Time;
	PlayerMenu* GameTime;

	void Render();
	void Update();

private:
	Graphics * mGraphics;
	AssetManager* mAssetManager;


protected:

};