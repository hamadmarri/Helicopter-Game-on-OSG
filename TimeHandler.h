//
//  TimeHandler.h
//
//	See main.cpp file header for credits
//


#ifndef __HelicopterProject__TimeHandler__
#define __HelicopterProject__TimeHandler__


#include <chrono>
#include <osgGA/GUIEventHandler>
#include "Observable.h"


// define Game
class Game;

class TimeHandler : public osgGA::GUIEventHandler, public Observable {
public:
	TimeHandler(Game *game);
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> nowTime;
	Game *game;
};


#include "Game.h"
#endif
