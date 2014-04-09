//
//  Rotor.cpp
//
//	See main.cpp file header for credits
//
//  The Rotor class implementation. The constructor will initilize
//	the magnitude to the gravity.
//


#include "Rotor.h"


Rotor::Rotor() {
	this->magnitude = WORLD_GRAVITY;
	this->unit = 0.1;
}



Rotor::Rotor(float unit) {
	this->magnitude = WORLD_GRAVITY;
	this->unit = unit;
}



void Rotor::setMagnitude(float magnitude) {
	if (magnitude > ((100 - 40) * this->unit) + WORLD_GRAVITY)
		this->magnitude = ((100 - 40) * this->unit) + WORLD_GRAVITY;
	else if (magnitude > 0.0)
		this->magnitude = magnitude;
}



void Rotor::setMagnitudeInPercentage(float percentage) {
	if (percentage > 100.0)
		percentage = 100.0;
	else if (percentage < 0.0)
		percentage = 0.0;
	
	setMagnitude(((percentage - 40) * this->unit) + WORLD_GRAVITY);
}



// decrease the magnitude and increase the magnitude
void Rotor::decreaseMagnitude() {
	setMagnitude(this->magnitude - this->unit);
}



void Rotor::increaseMagnitude() {
	setMagnitude(this->magnitude + this->unit);
}



// setNeutral to the gravity
void Rotor::setNeutral() {
	setMagnitude(WORLD_GRAVITY);
}



float Rotor::getMagnitude() const {
	return this->magnitude;
}



std::string Rotor::toString() {
	return "Rotor: magnitude=" + std::to_string(this->magnitude) + '\n';
}


