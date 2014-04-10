//	See main.cpp file header for credits
// This is the implementation of RotorPercentage class to set the percentage to a rotor instance and a boolean function
// to return true if that passed valued set.

#include "RotorPercentage.h"

// constructor two parameters , rotor, float
RotorPercentage::RotorPercentage(Rotor *rotor, float percentage) {
	this->rotor = rotor;                // set the passing rotor to our rotor
	this->percentage = percentage;          // set the passing float to our percentage
}


// boolean function
bool RotorPercentage::execute() {
	this->rotor->setMagnitudeInPercentage(this->percentage);  // set our rotor instance to our passing value and return true
                                                              // other than that return false
	return true;
}