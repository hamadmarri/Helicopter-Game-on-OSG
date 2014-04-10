//	See main.cpp file header for credits
//  This is implementation of RotorSwitchOff class. Implementing two main fuctions , the constructor to set the rotor ,and
// the boolean function to set the magnitude to zero and return true;

#include "RotorSwitchOff.h"

// the constructor passsing the rotor and set our rotor to the passing arguments.

RotorSwitchOff::RotorSwitchOff(Rotor *rotor) {
	this->rotor = rotor;
}


// set rotor magnitude to zero and return true 
bool RotorSwitchOff::execute() {
	this->rotor->setMagnitude(0.0);
	
	return true;
}