

#include "RotorSetMagnitude.h"


RotorSetMagnitude::RotorSetMagnitude(Rotor *rotor, float magnitude) {
	this->rotor = rotor;
	this->magnitude = magnitude;
}



bool RotorSetMagnitude::execute() {
	this->rotor->setMagnitude(this->magnitude);
	
	return true;
}