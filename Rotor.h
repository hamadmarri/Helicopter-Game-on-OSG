//
//  Rotor.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//  some modification on int

#ifndef testOsg_Rotor_h
#define testOsg_Rotor_h
// these libraries have been added 
#include <cmath>
#include <osg/Vec3f>
#include "Observer.h"
#include "WorldConstants.h"

class Rotor : public Observer {
public:
    Rotor();
    // I have added Event object in a function call Observe
    void Observe (Event event);
    // also the magnitude float type
    float magnitude;
};

#endif
