//
//  HelicopterMotion.cpp
//
//	See main.cpp file header for credits
//

#include "Motion.h"


Motion::Motion(osg::Vec3f initialPosition) {
	this->initialPosition = initialPosition;
}



void Motion::setNetForce(osg::Vec3f netForce) {
	this->netForce.set(netForce);
}




osg::Vec3f Motion::getCurrentVelocityVector() {
	return this->lastVelocity;
}



osg::Vec3f Motion::getCurrentPositionVector() {
	return this->lastPosition;
}



osg::Vec3f Motion::getCurrentNetForceVector() {
	return this->netForce;
}



float Motion::getGroundSpeed() {
	return sqrtf( (lastVelocity.x() * lastVelocity.x()) + (lastVelocity.y() * lastVelocity.y()) );
}



void Motion::setInitialVelocity(osg::Vec3f initialVelocity) {
	this->initialVelocity = initialVelocity;
}



