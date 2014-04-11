//	See main.cpp file header for credits

//   RotorSwitchOff class that will switch off the magnitude of a rotor to zero 0.0.
//   It has only two main fuctions , constructor and boolean functioin.
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//

#ifndef __HelicopterProject__RotorSwitchOff_h__
#define __HelicopterProject__RotorSwitchOff_h__

#include "Command.h"
#include "Rotor.h"

// RotorSwitchOff intherite from Command class public
class RotorSwitchOff : public Command {
public:
	RotorSwitchOff(Rotor *rotor);  // constructor passing a rotor
	bool execute();                 // boolean functioin
	
private:
	Rotor *rotor;              // rotor 
};

#endif 
