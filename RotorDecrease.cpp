//	See main.cpp file header for credits
// This is an implementation of RotorDecrease class. It has two main functions, a constructor to set the passing rotor
// instance to our rotor private membere, and a boolean function to retur true if our private member of a rotor
// called decreaseMagnitude or false instead.
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//


#include "RotorDecrease.h"

// constructor passing an instance of a rotor and set it to our private member rotor
RotorDecrease::RotorDecrease(Rotor *rotor) {
	this->rotor = rotor;
}


// used our passed rotor instance to call decreaseMagnitude function and return true, false instead if not.
bool RotorDecrease::execute() {
	this->rotor->decreaseMagnitude();
	
	return true;
}