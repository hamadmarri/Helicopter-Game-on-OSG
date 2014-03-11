//
//  Joystick.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
// SID: 200288569
//

#ifndef testOsg_Joystick_h
#define testOsg_Joystick_h

#include <cmath>
#include <osg/Vec3f>
#include "Observer.h"
#include "Configuration.h"
#include "WorldConstants.h"



class Joystick : public Observer {
public:
	Joystick();
	
	Joystick(Joystick &B);
	
	Joystick(double theta, double phi);
	
	void set_theta(double theta);
	double get_theta() const;
	
	void set_phi(double phi);
	double get_phi() const;

    osg::Vec3f getForce();
	
	
    void Update(Event event);

private:
	double toRadian(double degree);
	
	double theta;
	double phi;
};

#endif
