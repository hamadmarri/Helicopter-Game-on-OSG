//
//  RealTimeTest.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-26.
//
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
