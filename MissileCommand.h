//  MissileCommand.h
//
//
// This is MissileCommand class. The class inheriates from the Command class public. The main purpose of this class
// is to determine the Missile command type and translate it to actions depends on the command pass it to it.This
// done by setting a pointer of a missile instance and a missilecommand type. Then, a function call execute , will be
// called to determine the type of missile command and execute it by calling funcitons from the missile instance we have
// it in the class (pointer).

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
