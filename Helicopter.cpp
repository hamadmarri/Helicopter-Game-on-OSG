//
//  Helicopter.cpp
//
//  Created by Fares Alotaibi on 2014-03-02.
//	Credit: http://scenemodels.flightgear.org/objectview.php?id=3303278
//			http://hyperphysics.phy-astr.gsu.edu/hbase/airfri.html
//
//

#include "Helicopter.h"



// constructor of the helicopter from the model class
// here we will display the helicopter to the use once the constructor called.
Helicopter::Helicopter() : Model() {
	
	// using RK4 calculation as concrete class
	this->motion = new RK4();
    this->joystick = new Joystick();
	this->rotor = new Rotor();
	
    this->node->addChild(osgDB::readNodeFile("3124/EC-135_Douane.ac"));
	this->PAT->setPosition(osg::Vec3f(-10.0, -3000.0, -2000.0));
}



void Helicopter::Update(Event event){
    static float y = 0;
	static double t = 0;
	float viscousResistance = -6 * WORLD_PI * 4;

	// calculating the netForce depends on the joystick and the rotor
	this->motion.netForce.set(this->joystick->getForce().operator*(this->rotor->magnitude)
							  + osg::Vec3f(0.0, 0.0, -1).operator*(WORLD_GRAVITY)
							  + viscousResistance
							  );
	
	
    // here after calculating the forces and velocity , we have to update the position on the scence 
    
    this->PAT->setPosition(osg::Vec3f(
									  this->PAT->getPosition().x() + nextPosition.y() * cosf(y),
									  this->PAT->getPosition().y() + nextPosition.z(),
									  this->PAT->getPosition().z() + nextPosition.x() * cosf(y)
									  )
						   );
    
}



Joystick* Helicopter::getJoystick() {
	return this->joystick;
}



Rotor* Helicopter::getRotor() {
	return this->rotor;
}


