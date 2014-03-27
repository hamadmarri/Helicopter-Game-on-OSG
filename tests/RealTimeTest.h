//
//  RealTimeTest.h
//
//	See main.cpp file header for credits//
//

#ifndef testOsg_RealTimeTest_h
#define testOsg_RealTimeTest_h

#include <iostream>
#include <thread>
#include <assert.h>
#include "../Game.h"
#include "../AllCommands.h"

class RealTimeTest {
public:
    void run();
	
	static void hover();
	static void maxSpead();

    
private:
    static void Assert(float expected, float result, float delta);
    static Game game;
    
};


#endif
