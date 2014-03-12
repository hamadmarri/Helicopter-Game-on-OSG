//
//  Helicopter.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
// a Helicopter class inhereted from a Model class and Observer class. The helicopter has joystick, rotor, and offcourse it has
// a motion.
//

#ifndef testOsg_Helicopter_h
#define testOsg_Helicopter_h

#include "Joystick.h"
#include "Rotor.h"
#include "Model.h"
#include "Observer.h"
#include "RK4.h"
#include "WorldConstants.h"

class Helicopter : public Model, public Observer {
public:
    Helicopter();
    void Update(Event event);
	
	Joystick* getJoystick();
	Rotor* getRotor();
	
private:
	Joystick *joystick;
    Rotor *rotor;
    Motion *motion;
};


#endif
