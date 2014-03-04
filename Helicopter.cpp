//
//  Helicopter.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//	Credit: http://scenemodels.flightgear.org/objectview.php?id=3303278
//

#include "Helicopter.h"
#include "Model.h"
// constructor of the helicopter from the model class

Helicopter::Helicopter() : Model() {
    joystick = new Joystick();
   
    this->node->addChild(osgDB::readNodeFile("3124/EC-135_Douane.ac"));
	this->PAT->setPosition(osg::Vec3f(100.0, 0.0, 100.0));
	   
}

void Helicopter:: Observe(char event){
    static float y = 0;
	static double t = 0;
	
	
    
	this->motion.netForce.set(this->joystick->getForce().operator*(9.8)
							  + osg::Vec3f(0.0, 0.0, -1).operator*(9.8)
							  - osg::Vec3f(0.99 * this->motion.lastVelocity.x(),
										   0.99 * this->motion.lastVelocity.y(),
										   2.99 * this->motion.lastVelocity.z())
							  );
	
	
	t += 0.0166;
	osg::Vec3f nextPosition = this->motion.calculate_position_at(t);
	
	
	
    
    this->PAT->setPosition(osg::Vec3f(this->PAT->getPosition().x() + nextPosition.y() * cosf(y),
										   this->PAT->getPosition().y() + nextPosition.z(),
										   this->PAT->getPosition().z() + nextPosition.x() * cosf(y)));
    
    
}



