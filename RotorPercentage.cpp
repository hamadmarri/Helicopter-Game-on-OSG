

#include "RotorPercentage.h"


RotorPercentage::RotorPercentage(Rotor *rotor, float percentage) {
	this->rotor = rotor;
	this->percentage = percentage;
}



bool RotorPercentage::execute() {
	this->rotor->setMagnitudeInPercentage(this->percentage);
	
	return true;
}