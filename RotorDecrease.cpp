
#include "RotorDecrease.h"


RotorDecrease::RotorDecrease(Rotor *rotor) {
	this->rotor = rotor;
}



bool RotorDecrease::execute() {
	this->rotor->decreaseMagnitude();
	
	return true;
}