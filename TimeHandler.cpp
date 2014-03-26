//
//  TimeHandler.cpp
//  
//
//	See main.cpp file header for credits
//


#include "TimeHandler.h"


TimeHandler::TimeHandler() {
	this->previousTime = std::chrono::system_clock::now();
}



// we are handling eventyType 
bool TimeHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME) {
		
		// get current time
		this->nowTime = std::chrono::system_clock::now();
		
		// calculate duration
		std::chrono::duration<double> elapsedTime = this->nowTime - this->previousTime;
		
		// notify all observers
        NotifyAll(Event(EventType::UPDATE_POSITION, elapsedTime.count()));
		
		// shift time
		this->previousTime = this->nowTime;
	}
	
	return false;
}
