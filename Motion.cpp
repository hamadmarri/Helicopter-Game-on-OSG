//
//  HelicopterMotion.cpp
//  Physics
//
//  Created by Hamad Almarri on 1/31/2014.
//

#include "Motion.h"

Motion::Motion() {
	this->lastTime = 0;
}


osg::Vec3f Motion::calculate_position_at(double t) {
	// using RK4 method
	RK4 rk4;
	
	// state to
	State st;
	double dt;

	// get dt
	dt = (t - this->lastTime);
	
	// set last time to this time
	this->lastTime = t;
	
	// calculate for x coordinate
	st.x = this->initialPosition.x();
	st.v = this->initialVelocity.x();
	rk4.integrate(st, t, dt, netForce.x());
	this->lastPosition.x() = st.x;
	this->lastVelocity.x() = st.v;
	
	// calculate for y coordinate
	st.x = this->initialPosition.y();
	st.v = this->initialVelocity.y();
	rk4.integrate(st, t, dt, netForce.y());
	this->lastPosition.y() = st.x;
	this->lastVelocity.y() = st.v;
	
	// calculate for z coordinate
	st.x = this->initialPosition.z();
	st.v = this->initialVelocity.z();
	rk4.integrate(st, t, dt, netForce.z());
	this->lastPosition.z() = st.x;
	this->lastVelocity.z() = st.v;
	
	
	initialPosition = lastPosition;
	initialVelocity = lastVelocity;
	
	return this->lastPosition;
}



osg::Vec3f Motion::calculate_next_position(double dt) {
	// using RK4 method
	RK4 rk4;
	
	// state to
	State st;
	
	// calculate for x coordinate
	st.x = this->initialPosition.x();
	st.v = this->initialVelocity.x();
	rk4.integrate(st, 0, dt, netForce.x());
	this->lastPosition.x() = st.x;
	this->lastVelocity.x() = st.v;
	
	// calculate for y coordinate
	st.x = this->initialPosition.y();
	st.v = this->initialVelocity.y();
	rk4.integrate(st, 0, dt, netForce.y());
	this->lastPosition.y() = st.x;
	this->lastVelocity.y() = st.v;
	
	// calculate for z coordinate
	st.x = this->initialPosition.z();
	st.v = this->initialVelocity.z();
	rk4.integrate(st, 0, dt, netForce.z());
	this->lastPosition.z() = st.x;
	this->lastVelocity.z() = st.v;
	
	
	initialPosition = lastPosition;
	initialVelocity = lastVelocity;
	
	return this->lastPosition;
}









