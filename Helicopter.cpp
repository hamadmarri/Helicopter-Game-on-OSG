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
    
    this->node->addChild(osgDB::readNodeFile("3124/EC-135_Douane.ac"));
	this->PAT->setPosition(osg::Vec3f(100.0, 0.0, 100.0));
	   
}
