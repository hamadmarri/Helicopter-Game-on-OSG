//
//  TimeHandler.h
//
//	See main.cpp file header for credits
//

/* TimeHandler class inheritis from GUIEventHandler and Obserable class, to manage events. Events like time, get the current
   time , previous time, notify all observes classes, check collisions, and calculate the duration, time shifting, and logging.
 
 */


#ifndef __HelicopterProject__TimeHandler__
#define __HelicopterProject__TimeHandler__

// calling chrono library to measure time spans, like: one minute, two hours, or ten milliseconds.
#include <chrono>
#include <osgGA/GUIEventHandler>
#include "Observable.h"


// define Game
class Game;
// inheritance public from GUIEventHandler and Observable
class TimeHandler : public osgGA::GUIEventHandler, public Observable {
public:
    // constructor passing a game class
	TimeHandler(Game *game);
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
private:
    
	std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> nowTime;
	Game *game;
};


#include "Game.h"
#endif
