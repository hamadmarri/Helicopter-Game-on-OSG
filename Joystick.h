//
//  Joystick.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#ifndef testOsg_Joystick_h
#define testOsg_Joystick_h

#include <cmath>
#include <osg/Vec3f>

class Joystick {
public:
	Joystick() {}
	
	Joystick(Joystick &B) {
		this->theta = B.theta;
		this->phi = B.phi;
	}
	
	Joystick(double theta, double phi) {
		this->theta = theta;
		this->phi = phi;
	}
	
	void set_theta(double theta) { this->theta = theta; }
	void set_phi(double phi) { this->phi = phi; }
	
	double get_theta() const { return this->theta; }
	double get_phi() const { return this->phi; }
	
	/*
	 calculate the unit vector from the two angles(theta and phi)
	 */
	osg::Vec3f getForce() {
		osg::Vec3f F;
		F.x() = sin(toRadian(get_theta())) * cos(toRadian(get_phi()));
		F.y() = sin(toRadian(get_theta())) * sin(toRadian(get_phi()));
		F.z() = cos(toRadian(get_theta()));
		return F;
	}
	
	double toRadian(double degree) {
		return (degree * 3.14159265) / 180;
	}
	
private:
	double theta;
	double phi;
};

#endif
