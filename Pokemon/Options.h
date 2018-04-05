#include "menu.h"

class Options : public Menu {
public:
	Options();
	~Options();

	void Render();
	void Update();

private:
	Graphics * mGraphics;



protected:

};