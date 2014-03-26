//
//  SimulatorTest.cpp
//
//	See main.cpp file header for credits
//

#include "SimulatorTest.h"


SimulatorTest::SimulatorTest() {
	this->dt = double(1) / double(60);
}



void SimulatorTest::run() {

	hover();
	maxSpead();
	someSetOfJoystick_throttle_delayTest();
	returnBackToPositionZero();
}



void SimulatorTest::setUp() {
	this->helicopter = static_cast<Helicopter*>(ModelFactory::getInstance()->create(ModelsTypes::HELICOPTER));
	RotorNeutral rn(helicopter->getRotor());
	
	rn.execute();
	this->helicopter->reset();
	this->helicopter->setPosistion(osg::Vec3f(0, 0, 0));
}



void SimulatorTest::Assert(float expected, float result, float delta) {
	assert(expected >= result - delta && expected <= result + delta);
}



void SimulatorTest::hover() {
	std::cout << "\nhover test started:" << std::endl;
	
	setUp();
	Configuration::disactivateFriction();

	helicopter->getRotor()->increaseMagnitude();
	
	for (int i = 0; i < 10 * 60; i++)
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));

	
	
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



void SimulatorTest::maxSpead() {
	
	std::cout << "\nmaxSpead test started:" << std::endl;
	
	setUp();
	JoystickMoveForward jmf(helicopter->getJoystick());
	float oldV = 0;
	float newV = 0;
	
	Configuration::activateFriction();
	jmf.execute();
	
	
	do {
		oldV = newV;
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));
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



void SimulatorTest::someSetOfJoystick_throttle_delayTest() {
	std::cout << "\nsomeSetOfJoystick_throttle_delayTest test started:" << std::endl;
	
	setUp();
	
	// disavtivate friction
	Configuration::disactivateFriction();
	
	
	/*********** phase 1 **********/
	std::cout << "\nsomeSetOfJoystick_throttle_delayTest phase 1 test started:" << std::endl;
	JoystickMoveForward jmf1(helicopter->getJoystick());
	jmf1.execute();
	
	// wait 3s
	for (int i = 0; i < 3 * 60; i++)
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));
	

	Assert(2.536, helicopter->getAcceleration().x(), 0.01);
	Assert(0.0, helicopter->getAcceleration().y(), 0.01);
	Assert(-0.3339, helicopter->getAcceleration().z(), 0.01);
	
	Assert(7.608, helicopter->getVelocity().x(), 0.01);
	Assert(0.0, helicopter->getVelocity().y(), 0.01);
	Assert(-1.002, helicopter->getVelocity().z(), 0.01);
	
	Assert(11.412, helicopter->getPosistion().x(), 0.01);
	Assert(0.0, helicopter->getPosistion().y(), 0.01);
	Assert(-1.50225, helicopter->getPosistion().z(), 0.01);
	
	
	
	std::cout << "someSetOfJoystick_throttle_delayTest phase 1 test passed" << std::endl;
	std::cout << "someSetOfJoystick_throttle_delayTest phase 1 test results:" << std::endl;
	std::cout << "a = ("	<< helicopter->getAcceleration().x() << ", "
	<< helicopter->getAcceleration().y() << ", "
	<< helicopter->getAcceleration().z() << ")" << std::endl;
	std::cout << "v = ("	<< helicopter->getVelocity().x() << ", "
	<< helicopter->getVelocity().y() << ", "
	<< helicopter->getVelocity().z() << ")" << std::endl;
	std::cout << "p = ("	<< helicopter->getPosistion().x() << ", "
	<< helicopter->getPosistion().y() << ", "
	<< helicopter->getPosistion().z() << ")" << std::endl;
	
	
	
	
	
	/*********** phase 2 **********/
	std::cout << "\nsomeSetOfJoystick_throttle_delayTest phase 2 test started:" << std::endl;
	JoystickMoveLeft jml2(helicopter->getJoystick());
	RotorIncrease ri(helicopter->getRotor());
	jml2.execute();
	ri.execute();
	ri.execute();
	
	// wait 2s
	for (int i = 0; i < 2 * 60; i++)
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));
	
	
	Assert(0.0, helicopter->getAcceleration().x(), 0.01);
	Assert(2.6917, helicopter->getAcceleration().y(), 0.01);
	Assert(0.2456, helicopter->getAcceleration().z(), 0.01);
	
	Assert(7.608, helicopter->getVelocity().x(), 0.01);
	Assert(5.3834, helicopter->getVelocity().y(), 0.01);
	Assert(-0.5108, helicopter->getVelocity().z(), 0.01);
	
	Assert(26.628, helicopter->getPosistion().x(), 0.01);
	Assert(5.3834, helicopter->getPosistion().y(), 0.01);
	Assert(-3.01535, helicopter->getPosistion().z(), 0.01);
	
	
	std::cout << "someSetOfJoystick_throttle_delayTest phase 2 test passed" << std::endl;
	std::cout << "someSetOfJoystick_throttle_delayTest phase 2 test results:" << std::endl;
	std::cout << "a = ("	<< helicopter->getAcceleration().x() << ", "
	<< helicopter->getAcceleration().y() << ", "
	<< helicopter->getAcceleration().z() << ")" << std::endl;
	std::cout << "v = ("	<< helicopter->getVelocity().x() << ", "
	<< helicopter->getVelocity().y() << ", "
	<< helicopter->getVelocity().z() << ")" << std::endl;
	std::cout << "p = ("	<< helicopter->getPosistion().x() << ", "
	<< helicopter->getPosistion().y() << ", "
	<< helicopter->getPosistion().z() << ")" << std::endl;
	
	
	
	
	/*********** phase 3 **********/
	std::cout << "\nsomeSetOfJoystick_throttle_delayTest phase 3 test started:" << std::endl;
	JoystickMoveRight jmr2(helicopter->getJoystick());
	jmr2.execute();
	ri.execute();

	
	// wait 2s
	for (int i = 0; i < 2 * 60; i++)
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));
	
	
	
	Assert(0.0, helicopter->getAcceleration().x(), 0.01);
	Assert(-2.769, helicopter->getAcceleration().y(), 0.01);
	Assert(0.535, helicopter->getAcceleration().z(), 0.01);
	
	Assert(7.608, helicopter->getVelocity().x(), 0.01);
	Assert(-0.1546, helicopter->getVelocity().y(), 0.01);
	Assert(0.5592, helicopter->getVelocity().z(), 0.01);
	
	Assert(41.844, helicopter->getPosistion().x(), 0.01);
	Assert(10.6122, helicopter->getPosistion().y(), 0.01);
	Assert(-2.9669, helicopter->getPosistion().z(), 0.01);
	
	
	std::cout << "someSetOfJoystick_throttle_delayTest phase 2 test passed" << std::endl;
	std::cout << "someSetOfJoystick_throttle_delayTest phase 2 test results:" << std::endl;
	std::cout << "a = ("	<< helicopter->getAcceleration().x() << ", "
	<< helicopter->getAcceleration().y() << ", "
	<< helicopter->getAcceleration().z() << ")" << std::endl;
	std::cout << "v = ("	<< helicopter->getVelocity().x() << ", "
	<< helicopter->getVelocity().y() << ", "
	<< helicopter->getVelocity().z() << ")" << std::endl;
	std::cout << "p = ("	<< helicopter->getPosistion().x() << ", "
	<< helicopter->getPosistion().y() << ", "
	<< helicopter->getPosistion().z() << ")" << std::endl;
	
	
	
	std::cout << "someSetOfJoystick_throttle_delayTest all phases tests passed\n" << std::endl;
}




void SimulatorTest::returnBackToPositionZero() {
	std::cout << "\nreturnBackToPositionZero test started:" << std::endl;
	
	setUp();
	
	// disavtivate friction
	Configuration::disactivateFriction();
	
	RotorIncrease ri(helicopter->getRotor());
	RotorDecrease rd(helicopter->getRotor());
	
	ri.execute();
	
	// wait 10s
	for (int i = 0; i < 10 * 60; i++)
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));
	
	
	rd.execute();
	rd.execute();
	
	// wait 20s
	for (int i = 0; i < 20 * 60; i++)
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));

	
	ri.execute();
	ri.execute();
	
	// wait 10s
	for (int i = 0; i < 10 * 60; i++)
		helicopter->Update(Event(EventType::UPDATE_POSITION, this->dt));
	
	Assert(0, helicopter->getPosistion().z(), 1.0e-3);
	Assert(0, helicopter->getVelocity().z(), 1.0e-3);
	
	std::cout << "returnBackToPositionZero phase 2 test passed" << std::endl;
	std::cout << "returnBackToPositionZero phase 2 test results:" << std::endl;
	std::cout << "pz = " << helicopter->getPosistion().z() << std::endl;
	std::cout << "vz = " << helicopter->getVelocity().z() << std::endl;
	
	std::cout << "returnBackToPositionZero all phases tests passed\n" << std::endl;

}






