//
//  Event.cpp
//
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID: 200288569
//  Event.cpp has been implemented, it has only two functions
//

#include "Event.h"

// Event constructor has and EventType

Event::Event(EventType eventType) {
	this->eventType = eventType;
}


Event::Event(EventType eventType, float x, float y) {
	this->eventType = eventType;
	this->x = x;
	this->y = y;
}

