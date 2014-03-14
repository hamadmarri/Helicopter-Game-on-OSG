//
//  Rotor.h
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//  some modification on int

#ifndef __HelicopterProject__Rotor_h__
#define __HelicopterProject__Rotor_h__


// these libraries have been added 
#include <cmath>
#include <osg/Vec3f>
#include "Observer.h"
#include "WorldConstants.h"

class Rotor : public Observer {
public:
    Rotor();
    void Update(Event event);
	
	float getMgnitude() const;
	
private:
    float magnitude;
};

#endif
