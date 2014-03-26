//
//  SimulatorTest.h
//  HelicopterProject
//
//  Created by Hamad Almarri on 2014-03-22.
//  Copyright (c) 2014 Hamad Almarri. All rights reserved.
//

#ifndef __HelicopterProject__SimulatorTest__
#define __HelicopterProject__SimulatorTest__

#include <iostream>
#include <assert.h>
#include "../Helicopter.h"
#include "../ModelFactory.h"
#include "../AllCommands.h"
#include "../Configuration.h"


class SimulatorTest {
public:
	
	SimulatorTest();
	
	void run();
	
	void hover();
	void maxSpead();
	void someSetOfJoystick_throttle_delayTest();
	void returnBackToPositionZero();
	
private:
	void setUp();
	void Assert(float expected, float result, float delta);
	
	Helicopter *helicopter;
	float dt;
};

#endif /* defined(__HelicopterProject__SimulatorTest__) */
