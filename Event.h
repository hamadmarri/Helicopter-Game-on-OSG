//
//  Event.h
//  testOsg (this is the project name that I am working on to test the code forget about it)
//
//  Created by Fares Alotaibi 
//  SID : 200288569 
//

// Event class has been implemented at this point. Also, notice the numeration class has been used and implemented.

#ifndef testOsg_Event_h
#define testOsg_Event_h

// EventyType class

enum class EventType {
	MOVE_LEFT,
	MOVE_FORWARD,
	MOVE_RIGHT,
	MOVE_BACKWARD,
	CENTER,
	MOUSE_MOVEMENT,
	DECREASE,
	INCREASE,
	STAY_NEUTRAL,
	SWITCH_OFF,
	ROTATE_LEFT,
	ROTATE_RIGHT,
	UPDATE_POSITION
};

// Event class
class Event {
public:
	Event(EventType eventType);
	Event(EventType eventType, float x, float y);
    
	
	EventType getEventType() const;
	float getX() const;
	float getY() const;
	
private:
	EventType eventType;
	float x;
	float y;
};


#endif
