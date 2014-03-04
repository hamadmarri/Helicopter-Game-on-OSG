//
//  RK4.h
//  Physics
//
// Credeits: http://gafferongames.com/game-physics/integration-basics/
//

#ifndef Physics_RK4_h
#define Physics_RK4_h

//#include "Vector.h"
//#include <osg/Vec3f>


struct State {
	double x;
	double v;
};


struct Derivative
{
	double dx;          // derivative of position: velocity
	double dv;          // derivative of velocity: acceleration
};

class RK4 {
public:
	
	Derivative evaluate(const State &initial, double t, double dt, const Derivative &d, double force) {
		State state;
		state.x = initial.x + d.dx * dt;
		state.v = initial.v + d.dv * dt;
		
		Derivative output;
		output.dx = state.v;
		output.dv = force;
		return output;
	}
	
	
	void integrate(State &state, double t, double dt, double force) {
		Derivative a = evaluate(state, t, 0.0f, Derivative(), force);
		Derivative b = evaluate(state, t, dt * 0.5f, a, force);
		Derivative c = evaluate(state, t, dt * 0.5f, b, force);
		Derivative d = evaluate(state, t, dt, c, force);
		
		const double dxdt = 1.0f/6.0f * (a.dx + 2.0f * (b.dx + c.dx) + d.dx);
		const double dvdt = 1.0f/6.0f * (a.dv + 2.0f * (b.dv + c.dv) + d.dv);
		
		state.x = state.x + dxdt * dt * 10;
		state.v = state.v + dvdt * dt;
	}
};

#endif
