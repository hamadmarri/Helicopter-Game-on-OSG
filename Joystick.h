//
//  Joystick.h
//
//  Created by Fares Alotaibi on 2014-03-02.
// SID: 200288569
// A Joystick class. The joystick class has many functions to set the theta and the phi of it. It inherets the Observer class, as we decided to design Observer design, thus we need any change of event of the joystick will be observed and can be changed directly. This is why we inhereted from Observer. 

#ifndef __HelicopterProject__Joystick_h__
#define __HelicopterProject__Joystick_h__

#include <cmath>
#include <osg/Vec3f>
#include "Observer.h"
#include "Configuration.h"
#include "WorldConstants.h"


// it is not observer anymore now
class Joystick{
public:
	Joystick();
	
	Joystick(Joystick &B);
	
	Joystick(double theta, double phi);
	
	void set_theta(double theta);
	double get_theta() const;
	
	void set_phi(double phi);
	double get_phi() const;

    osg::Vec3f getForce();
	
	
    

private:
	double toRadian(double degree);
	
	double theta;
	double phi;
};

#endif
