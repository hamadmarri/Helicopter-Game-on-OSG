//
//  Event.cpp
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID: 200288569
//  Event.cpp has been implemented, it has only two functions 
//  Modified by Alotaibi, Fares on 25-03-2014



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
