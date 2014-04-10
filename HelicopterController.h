//
//  HelicopterController.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-26.
//
// HelilcopterController class.
//

#ifndef testOsg_HelicopterController_h
#define testOsg_HelicopterController_h

#include <vector>
#include <algorithm> // find
#include <osgGA/GUIEventHandler>
#include "Helicopter.h"
#include "Observable.h"
#include "Invoker.h"
#include "AllCommands.h"
#include "Configuration/Configuration.h"


class Game;

class HelicopterController : public osgGA::GUIEventHandler {
public:
	
	HelicopterController(Game *game, Helicopter *helicopter);
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
private:
	Helicopter *helicopter;
	Invoker commandsInvoker;
	Game *game;
};

#include "Game.h"
#endif
