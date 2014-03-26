//	See main.cpp file header for credits


#ifndef TESTS_H
#define TESTS_H

#include <cxxtest/TestSuite.h>
#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>
#include "../Model.h"
#include "../Helicopter.h"
#include "../ModelFactory.h"
#include "../DelayCommand.h"


class Test_Helicopter : public CxxTest::TestSuite {
private:
	Helicopter *helicopter;
	DelayCommand *delayFrame;
	float delta = 1.0e-5;
	
public:
    void setUp() {
		helicopter = static_cast<Helicopter*>(ModelFactory::getInstance()->create(ModelsTypes::HELICOPTER));
		helicopter->setPosistion(osg::Vec3f(0, 0, 0));
		delayFrame = new DelayCommand(double(1) / double(60));
	}
	
    void test_HOVER() {
		
		setUp();
		
		helicopter->getRotor()->increaseMagnitude();
		
		for (int i = 0; i < 10 * 60; i++) {
			helicopter->Update(Event(EventType::UPDATE_POSITION_WITH_NO_FRICTION));
			delayFrame->execute();
		}
		
		// after 10s should be at position 15m
		// x = 0 + 0*10 + 0.5 * 0.3 * (10)^2 = 15
		TS_ASSERT_DELTA(15.0, helicopter->getPosition().z(), delta);
    }
	
	
    void test_MaxSpead() {
		JoystickMoveForward jmf(helicopter->getJoystick());
		float oldV = 0;
		float newV = 0;
		
		helicopter->setPosistion(osg::Vec3f(0, 0, 0));
		jmf.execute();
		
		
		do {
			helicopter->Update(Event(EventType::UPDATE_POSITION_WITH_FRICTION));
			
			oldV = newV;
			newV = helicopter->getVelocity().x();
		} while (oldV < newV);
		
		
		// viscous resistance = v * (6 * WORLD_PI * 0.001 * 4)
		// if joystick(theta = 15, phi = 0) and throttle(9.8), then
		// ax = sin15 * 9.8 = 0.2588 * 9.8 = 2.53624
		// viscous resistance should be equal 2.53624
		// v * (6 * WORLD_PI * 0.001 * 4) = 2.53624 <= now solve for v
		// v = 2.53624 / (6 * WORLD_PI * 0.001 * 4)
		// v = 33.6379
		TS_ASSERT_DELTA(33.6379, helicopter->getVelocity().x(), delta);
    }

};
#endif // TESTS_H
