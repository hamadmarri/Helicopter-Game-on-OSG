//
//  TimeHandler.cpp
//  
//
//	See main.cpp file header for credits
//
/*
    This is the implementation for TimeHandler class. Handle events for time, detect collection, calculation duration,
    notify observes.
 */

#include "TimeHandler.h"


// implementation of the constructor passing an instance of a Game to set the previous time, game, and start logging.
TimeHandler::TimeHandler(Game *game) {
	this->previousTime = std::chrono::high_resolution_clock::now();
	
	this->game = game;
	game->logger.startLogging();
}



// we are handling eventyType 
bool TimeHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME) {
		
		// get current time
		this->nowTime = std::chrono::high_resolution_clock::now();
		
		// calculate duration
		std::chrono::duration<double> elapsedTime = this->nowTime - this->previousTime;
		
		// notify all observers
        NotifyAll(Event(EventType::UPDATE_POSITION, elapsedTime.count()));
		
		// check collisions
		game->collision.checkCollision();
		
		// shift time
		this->previousTime = this->nowTime;
		
		
		// log
		game->logger.log();
		
		return true;
	}
	
	return false;
}




