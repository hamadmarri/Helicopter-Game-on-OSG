//	See main.cpp file header for credits
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//

#ifndef __HelicopterProject__FireCommand_h__
#define __HelicopterProject__FireCommand_h__


#include "Command.h"
#include "Helicopter.h"

class FireCommand : public Command {
public:
	FireCommand(Helicopter *helicopter);
	bool execute();
	
private:
	Helicopter *helicopter;
};

#endif
