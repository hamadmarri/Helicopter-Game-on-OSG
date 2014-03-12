//
//  HelicopterMotion.cpp
//  Physics
//
//  Created by Hamad Almarri on 1/31/2014.
//

#include "Motion.h"


void Motion::setNetForce(osg::Vec3f netForce) {
	this->netForce.set(netForce);
}




osg::Vec3f Motion::getCurrentVelocity() {
	return this->lastVelocity;
}








