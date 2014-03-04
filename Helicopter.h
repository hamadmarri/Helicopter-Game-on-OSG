//
//  Helicopter.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#ifndef testOsg_Helicopter_h
#define testOsg_Helicopter_h

#include "Joystick.h"
#include "Rotor.h"
#include "Model.h"
#include "Observer.h"
#include "Motion.h"

class Helicopter : public Model , public Observer {
public:
    Helicopter();
    void Observe(char event);

private:
    Joystick *joystick;
    Rotor *rotor;
    Motion motion;
};


#endif
