//
//  Event.cpp
//
//	See main.cpp file header for credits
//


#include "Event.h"


// Event constructor has and EventType
Event::Event(EventType eventType) {
	this->eventType = eventType;
}


// some modification has been added , to the copy constructor
Event::Event(EventType eventType, float dt) {
	this->eventType = eventType;
	this->_dt = dt;
	
}



EventType Event::getEventType() const {
	return this->eventType;
}

// new gtter function
float Event::dt() const {
	return this->_dt;
}
