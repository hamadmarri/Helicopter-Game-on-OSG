//	See main.cpp file header for credits

#include "RotorSwitchOff.h"


RotorSwitchOff::RotorSwitchOff(Rotor *rotor) {
	this->rotor = rotor;
}



bool RotorSwitchOff::execute() {
	this->rotor->setMagnitude(0.0);
	
	return true;
}