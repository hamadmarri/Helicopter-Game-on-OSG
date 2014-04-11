
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
