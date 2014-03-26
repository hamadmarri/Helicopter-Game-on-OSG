//
//  Rotor.h
//
//	See main.cpp file header for credits
//
//	A Rotor class to handle the rotor in the helicopter.
//	It has been design to be inhertited from an Observer
//	class because we had decide to design an Observer design
//	to observe some events during playing the game.
//

#ifndef __HelicopterProject__Rotor_h__
#define __HelicopterProject__Rotor_h__


// these libraries have been added 
#include <cmath>
#include <osg/Vec3f>
#include "Observer.h"
#include "WorldConstants.h"

class Rotor{
public:
    Rotor();
    //void Update(Event event);
    void setMagnitude(float magnitude);
    void setMagnitudeInPercentage(float percentage);
	void decreaseMagnitude();
	void increaseMagnitude();
	void setNeutral();

	
	float getMgnitude() const;
	
private:
    float magnitude;
};

#endif
