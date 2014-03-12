//
//  HelicopterMotion.h
//  Physics
//
//	purpose:	this class takes care for motion
//				it gets the net forces and time and
//				returns the next estimated position
//  Created by Hamad Almarri on 1/31/2014.
//

#ifndef __Physics__Motion__
#define __Physics__Motion__

#include <iostream>
#include <cmath>
//#include "Vector.h"
#include <osg/Vec3f>
#include "RK4.h"



class Motion {
    
public:
	Motion();
	
	/*
	 it calculates the position at specific time
	 */
	osg::Vec3f calculate_position_at(double t);
	
		
	// members
	osg::Vec3f initialPosition;
	osg::Vec3f initialVelocity;
	osg::Vec3f netForce;
	
	osg::Vec3f lastPosition;
	osg::Vec3f lastVelocity;
	
protected:
	double lastTime;
};



#endif /* defined(__Physics__Motion__) */









