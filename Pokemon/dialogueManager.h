#ifndef DIALOGUEMANAGER_H
#define DIALOGUEMANGER_H

#include "DisplayText.h"

class DialogueManager : public TextScreen {
public:
	DialogueManager();
	~DialogueManager();
	void DisplayText();
	void Render();
	void Update();

private:

};

#endif // !DIALOGUEMANAGER_H

