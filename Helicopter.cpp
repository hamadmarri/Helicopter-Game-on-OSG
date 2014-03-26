//
//  Helicopter.cpp
//
//	See main.cpp file header for credits
//
//	Credit: http://scenemodels.flightgear.org/objectview.php?id=3303278
//			http://hyperphysics.phy-astr.gsu.edu/hbase/airfri.html
//


#include "Helicopter.h"



// constructor of the helicopter from the model class
// here we will display the helicopter to the use once the constructor called.
Helicopter::Helicopter() : Model() {
	
	// using RK4 calculation as concrete class
	this->motion = nullptr;
    this->joystick = new Joystick();
	this->rotor = new Rotor();
	
    this->node->addChild(osgDB::readNodeFile("3124/EC-135_Douane.ac"));
    
    reset();
	
}

Helicopter::~Helicopter() {
	if (this->motion)
		delete this->motion;
	
	if (this->joystick)
		delete this->joystick;
	
	if (this->rotor)
		delete this->rotor;
}

void Helicopter::setPosistion(osg::Vec3f newPos) {
	Model::setPosistion(newPos);
	
	if (this->motion)
		delete this->motion;
	// using RK4 calculation as concrete class
    //	this->motion = new RK4(this->getPosistion());
	this->motion = new EulerPhysics(this->getPosistion());
}


void Helicopter::Update(Event event) {
	
	if (event.getEventType() != EventType::UPDATE_POSITION)
		return;
    
	
    //	static const double t = (double(1) / double(60));
	osg::Vec3f viscousResistance = this->motion->getCurrentVelocity().operator*(0);
	
	if (Configuration::getInstance()->isFrictionActive()) {
        //		viscousResistance = this->motion->getCurrentVelocity();
        //		viscousResistance.operator*(viscousResistance);
        //		viscousResistance.operator*(0.0006);
		
		viscousResistance = this->motion->getCurrentVelocity().operator*(6 * WORLD_PI * 0.001 * 4);
	}
	
	this->motion->setNetForce(
							  this->joystick->getForce().operator*(this->rotor->getMagnitude())
							  + osg::Vec3f(0.0, 0.0, -1).operator*(WORLD_GRAVITY)
							  - viscousResistance
							  );
	
	
	osg::Vec3f nextPosition = this->motion->calculate_position_at(event.dt());
    Model::setPosistion(nextPosition);
    
}

void Helicopter::reset() {
	setPosistion(osg::Vec3f(-250, 0.0, 99 + WORLD_GROUND));
}




osg::Vec3f Helicopter::getVelocity() {
	return this->motion->getCurrentVelocity();
}



osg::Vec3f Helicopter::getAcceleration() {
	return (this->joystick->getForce().operator*(this->rotor->getMagnitude())
			+ osg::Vec3f(0.0, 0.0, -1).operator*(WORLD_GRAVITY));
}




Joystick* Helicopter::getJoystick() {
	return this->joystick;
}



Rotor* Helicopter::getRotor() {
	return this->rotor;
}


