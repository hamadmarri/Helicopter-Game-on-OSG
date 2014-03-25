//
//  EulerPhysics.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 2014-03-20.
//  Copyright (c) 2014 Hamad Almarri. All rights reserved.
//

#include "EulerPhysics.h"


EulerPhysics::EulerPhysics(osg::Vec3f initialPosition) : Motion(initialPosition) {
	
}


osg::Vec3f EulerPhysics::calculate_position_at(double dt) {
	
	// calculate for x coordinate
	this->lastPosition.x() = calculatePosition(this->initialPosition.x(), this->initialVelocity.x(), this->netForce.x(), dt);
	this->lastVelocity.x() = calculateVelocity(this->initialVelocity.x(), this->netForce.x(), dt);
	
	// calculate for y coordinate
	this->lastPosition.y() = calculatePosition(this->initialPosition.y(), this->initialVelocity.y(), this->netForce.y(), dt);
	this->lastVelocity.y() = calculateVelocity(this->initialVelocity.y(), this->netForce.y(), dt);
	
	// calculate for z coordinate
	this->lastPosition.z() = calculatePosition(this->initialPosition.z(), this->initialVelocity.z(), this->netForce.z(), dt);
	this->lastVelocity.z() = calculateVelocity(this->initialVelocity.z(), this->netForce.z(), dt);
	
	initialPosition = lastPosition;
	initialVelocity = lastVelocity;
	
	return this->lastPosition;
}



float EulerPhysics::calculatePosition(float x0, float v0, float a, float t) {
	return ((x0 + (v0 * t) + (0.5 * a * t * t)));
}



float EulerPhysics::calculateVelocity(float v0, float a, float t) {
	return (v0 + (a * t));
}






