//
//  Event.h
//
//	See main.cpp file header for credits
//
//	Event class is used by observable, where observable passes an Event to observers with
//	certain data such as dt
//
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//


#ifndef __HelicopterProject__Event_h__
#define __HelicopterProject__Event_h__


// EventyType class
enum class EventType {
	UPDATE_POSITION
};


// Event class
class Event {
public:
	Event(EventType eventType);
	Event(EventType eventType, float dt);
    
	
	EventType getEventType() const;
	float dt() const;
private:
	EventType eventType;
	float _dt;
	
};


#endif
