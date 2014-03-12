//
//  Rotor.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID : 200288569
//  The Rotor class implementation. The constructor will initilize the magnitude to the gravity. The update function will handle an event passing to it.

#include "Rotor.h"


Rotor::Rotor() {
	this->magnitude = WORLD_GRAVITY;
}


// update function to handle the event
void Rotor::Update(Event event){
    
    switch(event.getEventType()) {
        case EventType::DECREASE:  // if decrease then set the magnituide
			this->magnitude -= 0.3;
			break;
		case EventType::INCREASE:  // if increase
			this->magnitude += 0.3;
			break;
		case EventType::SWITCH_OFF:   // if switch off then 0 
            this->magnitude = 0;
            break;
		case EventType::STAY_NEUTRAL: //case EventType::CENTER:
            this->magnitude = WORLD_GRAVITY;
            break;
        default:
            break;
            
    }
	
}



float Rotor::getMgnitude() const {
	return this->magnitude;
}



