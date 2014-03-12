//
//  Joystick.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
// SID: 200288569
// A Joystick class. The joystick class has many functions to set the theta and the phi of it. It inherets the Observer class, as we decided to design Observer design, thus we need any change of event of the joystick will be observed and can be changed directly. This is why we inhereted from Observer. 

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
