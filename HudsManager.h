// 
// HudsManager is responsible for adding huds display on the screen
// it arranges huds in left/right alignments
// and also it can create huds dynamically so the client class doesn't worry about
// arranging huds on the screen.
//
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//

#ifndef __HelicopterProject__HudManager_h__
#define __HelicopterProject__HudManager_h__

#include <vector>
#include "Hud.h"


enum class HudAlignment {
	LEFT, RIGHT
};


class Game;

class HudsManager {
public:
	
	HudsManager(Game *game, unsigned int initial_Y_Position);
	~HudsManager();
	
	Hud* createHud(HudAlignment hudAlignment);
	void removeHud(Hud* hud);
	
	void hide();
	void show();
	
private:
	std::vector<Hud*> leftHuds;
	std::vector<Hud*> rightHuds;
	unsigned int initial_Y_Position;
	Game *game;
};


#include "Game.h"
#endif
