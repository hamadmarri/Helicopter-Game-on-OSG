//
//  HelicopterMotion.h
//
//	purpose:	this abstract class takes care for motion
//				it gets the net forces and time and
//				returns the next estimated position.
//				Need concrete class to implement calculate_position_at function
//
//	See main.cpp file header for credits
//

#ifndef __HelicopterProject__Motion__
#define __HelicopterProject__Motion__

#include <osg/Vec3f>


class Motion {
    
public:
	
	Motion(osg::Vec3f initialPosition);
	
	virtual ~Motion() { };
	
	/*
		abstract function to calculate the position at specific time
	 */
	virtual osg::Vec3f calculate_position_at(double t) = 0;
	
	void setNetForce(osg::Vec3f netForce);
	osg::Vec3f getCurrentVelocity();
	
protected:
	// members
	osg::Vec3f initialPosition;
	osg::Vec3f initialVelocity;
	osg::Vec3f netForce;
	
	osg::Vec3f lastPosition;
	osg::Vec3f lastVelocity;
	
};



#endif /* defined(__Physics__Motion__) */









