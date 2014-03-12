//
//  Rotor.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID : 200288569
//

#include "Rotor.h"


Rotor::Rotor() {
	this->magnitude = WORLD_GRAVITY;
}



void Rotor::Update(Event event){
    
    switch(event.getEventType()) {
        case EventType::DECREASE:
			this->magnitude -= 0.3;
			break;
		case EventType::INCREASE:
			this->magnitude += 0.3;
			break;
		case EventType::SWITCH_OFF:
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



