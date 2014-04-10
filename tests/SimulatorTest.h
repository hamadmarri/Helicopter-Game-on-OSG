//
//  SimulatorTest.h
//
//	See main.cpp file header for credits
//

#ifndef __HelicopterProject__SimulatorTest__
#define __HelicopterProject__SimulatorTest__

#include <iostream>
#include <assert.h>
#include "../Helicopter.h"
#include "../ModelFactory.h"
#include "../AllCommands.h"
#include "../Configuration/Configuration.h"
#include "../Game.h"


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
	Game *game;
};

#endif /* defined(__HelicopterProject__SimulatorTest__) */
