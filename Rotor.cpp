//
//  Rotor.cpp
//
//	See main.cpp file header for credits
//
//  The Rotor class implementation. The constructor will initilize
//	the magnitude to the gravity. The update function will handle an event passing to it.
//


#include "Rotor.h"


Rotor::Rotor() {
	this->magnitude = WORLD_GRAVITY;
}

void Rotor::setMagnitude(float magnitude) {
	if (magnitude > ((100 - 40) * 0.3) + WORLD_GRAVITY)
		this->magnitude = ((100 - 40) * 0.3) + WORLD_GRAVITY;
	else if (magnitude > 0.0)
		this->magnitude = magnitude;
}


void Rotor::setMagnitudeInPercentage(float percentage) {
	if (percentage > 100.0)
		percentage = 100.0;
	else if (percentage < 0.0)
		percentage = 0.0;
	
	setMagnitude(((percentage - 40) * 0.3) + WORLD_GRAVITY);
}



// decrease the magnitude and increase the magnitude
void Rotor::decreaseMagnitude() {
	setMagnitude(this->magnitude - 0.3);
}

void Rotor::increaseMagnitude() {
	setMagnitude(this->magnitude + 0.3);
}

// setNeutral to the gravity
void Rotor::setNeutral() {
	setMagnitude(WORLD_GRAVITY);
}

float Rotor::getMgnitude() const {
	return this->magnitude;
}



