//
//  Event.h
//
//  Created by Fares Alotaibi 
//  SID : 200288569 
//
// Event class has been implemented at this point. Also, notice the numeration class has been used and implemented.


#ifndef __HelicopterProject__Event_h__
#define __HelicopterProject__Event_h__


// EventyType class
enum class EventType {
//	MOVE_LEFT,
//	MOVE_FORWARD,
//	MOVE_RIGHT,
//	MOVE_BACKWARD,
//	CENTER,
//	MOUSE_MOVEMENT,
//	DECREASE,
//	INCREASE,
//	STAY_NEUTRAL,
//	SWITCH_OFF,
//	ROTATE_LEFT,
//	ROTATE_RIGHT,
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
