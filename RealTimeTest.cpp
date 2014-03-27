//
//  RealTimeTest.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-26.
// 
//

#include "RealTimeTest.h"

Game RealTimeTest::game;


void RealTimeTest::run() {
	
	game.initialize();
	
	std::thread startHoverTest(RealTimeTest::hover);
	std::thread startMaxSpeadTest(RealTimeTest::maxSpead);
	
	game.run();
	
	startHoverTest.join();
	startMaxSpeadTest.join();
}



void RealTimeTest::Assert(float expected, float result, float delta) {
	assert(expected >= result - delta && expected <= result + delta);
}

