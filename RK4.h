//
//  RK4.h
//
// Credeits: http://gafferongames.com/game-physics/integration-basics/
//

#ifndef __HelicopterProject_RK4_h__
#define __HelicopterProject_RK4_h__

#include "Motion.h"
#include <cmath>
#include <osg/Vec3f>

struct State {
	double x;
	double v;
};


struct Derivative
{
	double dx;          // derivative of position: velocity
	double dv;          // derivative of velocity: acceleration
};


class RK4 : public Motion {
public:
	RK4();
	
	/*
	 it calculates the position at specific time
	 */
	osg::Vec3f calculate_position_at(double t);
	
	
protected:
	Derivative evaluate(const State &initial, double t, double dt, const Derivative &d, double force);
	void integrate(State &state, double t, double dt, double force);
	
	double lastTime;
};

#endif
