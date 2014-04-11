//
//  Joystick.h
//
//	See main.cpp file header for credits
//
//	A Joystick class. The joystick class has many functions to set the theta
//	and the phi of it.
//
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//

#ifndef __HelicopterProject__Joystick_h__
#define __HelicopterProject__Joystick_h__

#include <cmath>
#include <osg/Vec3f>
#include <string>
#include "Configuration.h"
#include "WorldConstants.h"
#include "Loggable.h"

// it is not observer anymore now
class Joystick : public Loggable {
public:
	Joystick();
	
	Joystick(Joystick &B);
	
	Joystick(double theta, double phi);
	
	void set_theta(double theta);
	double get_theta() const;
	
	void set_phi(double phi);
	double get_phi() const;

    osg::Vec3f getForce();
	
	std::string toString();

private:
	double toRadian(double degree);
	
	double theta;
	double phi;
};

#endif
