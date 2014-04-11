//
//  HelicopterMotion.cpp
//  This is Motion class member implementaiton. It imlements initial position, set the net force, get the current velocity
//  vector, get the position vector, get the the net force vector, get the ground speed , and set the initial veclocity.
//
//	See main.cpp file header for credits
//
//
//	created by Hamad Almarri
//

#include "Motion.h"

// a copy constructor to set the initial velocity , it takes a paramter from a vec3 OSG
Motion::Motion(osg::Vec3f initialPosition) {
	this->initialPosition = initialPosition;
}


// a setter function to set the net force, it takes a parameter from a vec3
void Motion::setNetForce(osg::Vec3f netForce) {
	this->netForce.set(netForce);
}



// getter function to return the last velocity
osg::Vec3f Motion::getCurrentVelocityVector() {
	return this->lastVelocity;
}


// getter function to return the last position
osg::Vec3f Motion::getCurrentPositionVector() {
	return this->lastPosition;
}


// getter function to return the net force
osg::Vec3f Motion::getCurrentNetForceVector() {
	return this->netForce;
}


// a geeter function return the ground speed by computing square root of (last velocity^2 x + last velocity^2 y)

float Motion::getGroundSpeed() {
	return sqrtf( (lastVelocity.x() * lastVelocity.x()) + (lastVelocity.y() * lastVelocity.y()) );
}


// setter function to set the initial velocity vector 
void Motion::setInitialVelocity(osg::Vec3f initialVelocity) {
	this->initialVelocity = initialVelocity;
}



