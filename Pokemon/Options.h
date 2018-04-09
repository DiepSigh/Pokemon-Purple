#include "menu.h"

class Options : public Menu {
public:
	Options();
	Options(float, float, Texture*);
	~Options();

	static Options* sInstance;
	static Options* Instance();

	Options* textSpeed;
	Options* btlAnimation;
	Options* btlStyle;
	Options* Cancel;
	Options* Fast;
	Options* Medium;
	Options* Slow;
	Options* On;
	Options* Off;
	Options* Shift;
	Options* Set;
	Options* CursorO;

	void OptionsState();

	void Render();
	void Update();

	//Cursor Controls
	void oCursorLeft();
	void oCursorRight();
	void oCursorUp();
	void oCursorDown();


private:
	Graphics * mGraphics;
	AssetManager* mAssetManager;



protected:

};