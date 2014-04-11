// This is the implementation of MissileCommand class. It has two main functions to set the command type and the missile.The
// second function is called execute to execute the command depends on the command passed to it.
//

#include "MissileCommand.h"

// a constructor passing two parameters, a pointer of a missile , and a missileCommandType
MissileCommand::MissileCommand(Missile *missile, MissileCommandType type) {
	this->missile = missile;            // setting the missile, and the type
	this->type = type;
}


// boolean function to determine the command passed to it
bool MissileCommand::execute() {
	switch (this->type) {
		case MissileCommandType::INCREMENT_INCLINATION_ANGLE:       // if increment inclination
			this->missile->incrementInclinationAngle();             // execute incrementInclinationAngle()
			break;
		case MissileCommandType::DECREMENT_INCLINATION_ANGLE:       // if decrement inclination angle
			this->missile->decrementInclinationAngle();             // execute the decrementInclinationAngle()
			break;
		case MissileCommandType::INCREMENT_INITIAL_SPEED:           //  if increment initial speed
			this->missile->incrementIintialSpeed();                 // execute the incrementInitialSpeed()
			break;
		case MissileCommandType::DECREMENT_INITIAL_SPEED:           // if decrement initial speed
			this->missile->decrementIintialSpeed();                 //  execute decrementInitialSpeed() 
			break;
		default:
			break;
	}
	
	return true;
}