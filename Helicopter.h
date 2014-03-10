//
//  Helicopter.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//

#ifndef testOsg_Helicopter_h
#define testOsg_Helicopter_h

#include "Joystick.h"
#include "Rotor.h"
#include "Model.h"
#include "Observer.h"
#include "Motion.h"
#include "WorldConstants.h"

class Helicopter : public Model , public Observer {
public:
    Helicopter();
    void Observe(Event event);


    Joystick *joystick;
    Rotor *rotor;
    Motion motion;
};


#endif
