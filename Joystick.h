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
#include "Observer.h"
#include "Configuration.h"
#include "WorldConstants.h"



class Joystick :public Observer {
public:
	Joystick();
	
	Joystick(Joystick &B);
	
	Joystick(double theta, double phi);
	
	void set_theta(double theta);
	void set_phi(double phi);
	
	double get_theta() const;
	double get_phi() const;
	double toRadian(double degree);
    
    void Observe(Event event);
    
    
	osg::Vec3f getForce();
    
private:
	double theta;
	double phi;
};

#endif
