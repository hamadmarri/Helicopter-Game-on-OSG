//	See main.cpp file header for credits

#include "RotorDecrease.h"


RotorDecrease::RotorDecrease(Rotor *rotor) {
	this->rotor = rotor;
}



bool RotorDecrease::execute() {
	this->rotor->decreaseMagnitude();
	
	return true;
}