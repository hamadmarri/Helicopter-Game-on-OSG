
#ifndef __HelicopterProject__MissileCommand_h__
#define __HelicopterProject__MissileCommand_h__

#include "Command.h"
#include "Missile.h"


enum class MissileCommandType {
	INCREMENT_INCLINATION_ANGLE, DECREMENT_INCLINATION_ANGLE,
	INCREMENT_INITIAL_SPEED, DECREMENT_INITIAL_SPEED
};


class MissileCommand : public Command {
public:
	MissileCommand(Missile *missile, MissileCommandType type);
	bool execute();
	
private:
	Missile *missile;
	MissileCommandType type;
};

#endif
