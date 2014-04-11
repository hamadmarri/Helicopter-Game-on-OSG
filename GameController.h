//
//  GameController.h
//
//	See main.cpp file header for credits
//
//	GameController takes care of controlling the helicopter and other game options such as
//	hide/show help screen, enable/disable friction, and missile's inclination angle and initial speed
//	It gets key, mouse events from GUIEventHandler virtual function handle
//

#ifndef __HelicopterProject__HelicopterController_h__
#define __HelicopterProject__HelicopterController_h__


#include <osgGA/GUIEventHandler> // handle function
#include "Helicopter.h"
#include "Observable.h"
#include "Invoker.h"
#include "AllCommands.h"
#include "Configuration.h"


// define Game
class Game;


class GameController : public osgGA::GUIEventHandler {
public:
	
	// constructor with setting game and helicopter to control
	GameController(Game *game, Helicopter *helicopter);
	
	
	// implementation of handle function that comes from GUIEventHandler class
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
private:
	
	// helicopter to be controlled
	Helicopter *helicopter;
	
	// game to be controlled
	Game *game;
	
	// adding all commands on commandsInvoker and execute them
	Invoker commandsInvoker;
};


// since interdependent header includes,
// including Game.h should be after GameController class
#include "Game.h"
#endif


