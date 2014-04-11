//
//  Rotor.h
//
//	See main.cpp file header for credits
//
//	A Rotor class to handle the rotor in the helicopter. The main purpose of this class is to setMagnitude,setMagnitude in
//  in percentage, decrease the magnitude, increase the magnitude, set the neutral.
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
#include "Loggable.h"


class Rotor {
public:
    Rotor();            // constructors
	Rotor(float unit);
	
    // member functions
    void setMagnitude(float magnitude);
    void setMagnitudeInPercentage(float percentage);
	void decreaseMagnitude();
	void increaseMagnitude();
	void setNeutral();
	float getMagnitude() const;
	std::string toString();
	
private:        // two private members float
    float magnitude;
	float unit;
};

#endif
