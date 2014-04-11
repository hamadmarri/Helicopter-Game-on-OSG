//	See main.cpp file header for credits
//  The joystickMouseMovement class. 
//  

#ifndef __HelicopterProject__JoystickMouseMovement_h__
#define __HelicopterProject__JoystickMouseMovement_h__

#include "Command.h"
#include "Joystick.h"
#include "Configuration.h"

class Game;


class JoystickMouseMovement : public Command {
public:
	JoystickMouseMovement(Game *game, Joystick *joystick, float xCartesian, float yCartesian);
	virtual bool execute();
	
private:
	Game *game;
	Joystick *joystick;
	float xCartesian;
	float yCartesian;
};

#include "Game.h"
#endif 
