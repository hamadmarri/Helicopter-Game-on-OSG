

#include "MissileCommand.h"


MissileCommand::MissileCommand(Missile *missile, MissileCommandType type) {
	this->missile = missile;
	this->type = type;
}



bool MissileCommand::execute() {
	switch (this->type) {
		case MissileCommandType::INCREMENT_INCLINATION_ANGLE:
			this->missile->incrementInclinationAngle();
			break;
		case MissileCommandType::DECREMENT_INCLINATION_ANGLE:
			this->missile->decrementInclinationAngle();
			break;
		case MissileCommandType::INCREMENT_INITIAL_SPEED:
			this->missile->incrementIintialSpeed();
			break;
		case MissileCommandType::DECREMENT_INITIAL_SPEED:
			this->missile->decrementIintialSpeed();
			break;
		default:
			break;
	}
	
	return true;
}