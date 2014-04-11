//
//  Rotor.cpp
//
//	See main.cpp file header for credits
//
//  The Rotor class implementation to implements increase magnitude , decrease magnitude, set natural, get magnitude.All
//  the main features of a rotor has been implemented below.
//
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//


#include "Rotor.h"

// a construcotor will set the magnitude to the world_gravity and the unit to 0.1
Rotor::Rotor() {
	this->magnitude = WORLD_GRAVITY;
	this->unit = 0.1;
}


// a copy constructor passing an integer to be passed to the unit , and at the same time set the magnitude to gravity
Rotor::Rotor(float unit) {
	this->magnitude = WORLD_GRAVITY;
	this->unit = unit;
}


// set magnitude function to take the passing argumeent and check it is larger than the fixed gravity
// by doing the 100-40 and multiply it by the unit then add it to the gravity. Otherwise
// set the magnitude to the passing argumment float.
void Rotor::setMagnitude(float magnitude) {
	if (magnitude > ((100 - 40) * this->unit) + WORLD_GRAVITY)   // here we check the value
		this->magnitude = ((100 - 40) * this->unit) + WORLD_GRAVITY; // it is is, then set it
	else if (magnitude > 0.0)  // if it larger than 0 , then set it directly
		this->magnitude = magnitude;
}


// set the magnitude in percentage function, it will pass a float and check if it is larger than 100,
// then inform the percentage to be 100. If it is less than 0, which is wrong offcourse, then we inforce
// it to be zero. Then we set the magnitude by taking this percentage and subtract it from 40 and multiply
// it by the unit, then add it the the gravity.
void Rotor::setMagnitudeInPercentage(float percentage) {
	if (percentage > 100.0)     // assure that our passsing parameter is not larger than 100 or less than 0
		percentage = 100.0;
	else if (percentage < 0.0)
		percentage = 0.0;
	
	setMagnitude(((percentage - 40) * this->unit) + WORLD_GRAVITY);  // set the magnitude in percentage
}



// decrease the magnitude by substract the magnitude from the unit
void Rotor::decreaseMagnitude() {
	setMagnitude(this->magnitude - this->unit);
}


// increase magnitude by adding the magnitude to the unit
void Rotor::increaseMagnitude() {
	setMagnitude(this->magnitude + this->unit);
}



// setNeutral to the gravity
void Rotor::setNeutral() {
	setMagnitude(WORLD_GRAVITY);
}


// get magnitude by return the magnitude
float Rotor::getMagnitude() const {
	return this->magnitude;
}


// converting the magnitude to a string function
std::string Rotor::toString() {
	return "Rotor: magnitude=" + std::to_string(this->magnitude) + '\n';
}


