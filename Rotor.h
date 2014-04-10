//
//  Rotor.h
//
//	See main.cpp file header for credits
//
//	A Rotor class to handle the rotor in the helicopter.
//
//
// 
// testOsg_RealTimeTest_h

#ifndef __HelicopterProject__Rotor_h__
#define __HelicopterProject__Rotor_h__


// these libraries have been added 
#include <cmath>
#include <osg/Vec3f>
#include <string>
#include "Observer.h"
#include "WorldConstants.h"
#include "Logger/Loggable.h"


class Rotor {
public:
    Rotor();
	Rotor(float unit);
	
    //void Update(Event event);
    void setMagnitude(float magnitude);
    void setMagnitudeInPercentage(float percentage);
	void decreaseMagnitude();
	void increaseMagnitude();
	void setNeutral();
	float getMagnitude() const;
	std::string toString();
	
private:
    float magnitude;
	float unit;
};

#endif
