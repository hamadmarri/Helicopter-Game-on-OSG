//	See main.cpp file header for credits
// This is the implementation of RotorIncrease class. The implementation is two function , a constructor that will set the passsing rotor instance to our rotor privat member, and the second function is a boolean function return true if the
// increaseMagnitude has been called or false if not.

#include "RotorIncrease.h"

// a constructor passing a rotor instance and set it to our private member rotor
RotorIncrease::RotorIncrease(Rotor *rotor) {
	this->rotor = rotor;
}


// return true if the function increaseMagnitude has been called or false if not 
bool RotorIncrease::execute() {
	this->rotor->increaseMagnitude();
	
	return true;
}