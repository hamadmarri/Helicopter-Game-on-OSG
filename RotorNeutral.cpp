//	See main.cpp file header for credits
// This is an implementation of RotorNeutral class , the implementation is two main functions, a constructor and
//  a boolean function. The constructor will set the passing instance of a rotor and set it to our private member
// rotor , and the boolena function will return true if the natural set or false if not.
#include "RotorNeutral.h"

// the constructor , passing an instance of a rotor and set it to our private member rotor
RotorNeutral::RotorNeutral(Rotor *rotor) {
	this->rotor = rotor;
}


// a boolena function return true if rotor natural has been set or not
bool RotorNeutral::execute() {
	this->rotor->setNeutral();
	
	return true;
}