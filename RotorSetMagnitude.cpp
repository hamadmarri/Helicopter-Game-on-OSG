// This is an implementation of RotorSetMagnitude class. The implementation of two main functions, a constructor to take
// a float number and pass it to the rotor magnitude and set it, and a boolean function to return true of the value
// has been passed.

#include "RotorSetMagnitude.h"

// the main consturctor passing two parameters , rotor, float
RotorSetMagnitude::RotorSetMagnitude(Rotor *rotor, float magnitude) {
	this->rotor = rotor;    // we set the rotor to our rotor
	this->magnitude = magnitude; // we take our float magnitude and set the value passed to it
}


// boolean function to return true if magnitude set
bool RotorSetMagnitude::execute() {
	this->rotor->setMagnitude(this->magnitude);
	
	return true;
}