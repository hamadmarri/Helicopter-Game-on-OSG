//
//  RealTimeTest.cpp
//
//	See main.cpp file header for credits 
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

void RealTimeTest::maxSpead() {
    
	DelayCommand dc(15);
	dc.execute();
	
	Helicopter *helicopter = game.getHelicopter();
	JoystickMoveForward jmf(helicopter->getJoystick());
	RotorNeutral rn(helicopter->getRotor());
	float oldV = 0;
	float newV = 0;
	
	std::cout << "\nmaxSpead test started:" << std::endl;
	
	game.getConfiguration()->activateFriction();
	helicopter->reset();
	helicopter->setPosistion(osg::Vec3f(0, 0, 0));
	jmf.execute();
	rn.execute();
	
	
	do {
		oldV = newV;
		dc.execute();
		newV = helicopter->getVelocity().x();
	} while (oldV < newV);
	
	
	// viscous resistance = v * (6 * WORLD_PI * 0.001 * 4)
	// if joystick(theta = 15, phi = 0) and throttle(9.8), then
	// ax = sin15 * 9.8 = 0.2588 * 9.8 = 2.53624
	// viscous resistance should be equal 2.53624
	// v * (6 * WORLD_PI * 0.001 * 4) = 2.53624 <= now solve for v
	// v = 2.53624 / (6 * WORLD_PI * 0.001 * 4)
	// v = 33.6379
	Assert(33.6379, helicopter->getVelocity().x(), 0.01);
	
	std::cout << "maxSpead test passed" << std::endl;
	std::cout << "maxSpead test results:" << std::endl;
	std::cout << "vx = " << helicopter->getVelocity().x() << std::endl;
    
}


