//
//  RK4.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 2014-03-11.
//


#include "RK4.h"



RK4::RK4() {
	this->lastTime = 0;
}



Derivative RK4::evaluate(const State &initial, double t, double dt, const Derivative &d, double force) {
	State state;
	state.x = initial.x + d.dx * dt;
	state.v = initial.v + d.dv * dt;
	
	Derivative output;
	output.dx = state.v;
	output.dv = force;
	return output;
}



void RK4::integrate(State &state, double t, double dt, double force) {
	Derivative a = evaluate(state, t, 0.0f, Derivative(), force);
	Derivative b = evaluate(state, t, dt * 0.5f, a, force);
	Derivative c = evaluate(state, t, dt * 0.5f, b, force);
	Derivative d = evaluate(state, t, dt, c, force);
	
	const double dxdt = 1.0f/6.0f * (a.dx + 2.0f * (b.dx + c.dx) + d.dx);
	const double dvdt = 1.0f/6.0f * (a.dv + 2.0f * (b.dv + c.dv) + d.dv);
	
	state.x = state.x + dxdt * dt * 10;
	state.v = state.v + dvdt * dt;
}



osg::Vec3f RK4::calculate_position_at(double t) {
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



