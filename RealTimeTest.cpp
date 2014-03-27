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



void RealTimeTest::hover() {
	
	DelayCommand dc(2);
	DelayCommand wait10s(10);
	dc.execute();
	
	std::cout << "\nhover test started:" << std::endl;
	
	game.getConfiguration()->disactivateFriction();
	Helicopter *helicopter = game.getHelicopter();
	
	helicopter->reset();
	helicopter->setPosistion(osg::Vec3f(0, 0, 0));
	helicopter->getRotor()->increaseMagnitude();
	
	wait10s.execute();
	
	
	// after 10s should be at position 15m
	// a = 0.3
	// x = 0 + 0*10 + 0.5 * 0.3 * (10)^2 = 15
	// v = 0 + a * t
	// v = 0.3 * 10 = 3
    
	Assert(15.0, helicopter->getPosistion().z(), 1.0e-1);
	Assert(3.0, helicopter->getVelocity().z(), 1.0e-1);
	Assert(0.3, helicopter->getAcceleration().z(), 1.0e-1);
	
	std::cout << "hover test passed" << std::endl;
	std::cout << "hover test results:" << std::endl;
	std::cout << "pz = " << helicopter->getPosistion().z() << std::endl;
	std::cout << "vz = " << helicopter->getVelocity().z() << std::endl;
	std::cout << "az = " << helicopter->getAcceleration().z() << std::endl;
    
}

