//
//  Sky.cpp
//
//	See main.cpp file header for credits
//
//  The implelmentation of sky model has been created here.
//	it has only one constructor , whenver an instance created,
//	the sky model will be in the detailed position below directly.
//


#include "Sky.h"


// constructor to display the skydome in some position
Sky::Sky(Game *game) : Model(game) {
    this->node->addChild(osgDB::readNodeFile("skydome.osgt"));   // calling the file from datafile osg
	this->matrixTransform->setMatrix(osg::Matrix::translate(-25000.0f, -25000.0f, -5000.0f)  // set the position
				   * osg::Matrix::rotate(osg::DegreesToRadians(90.0f),osg::Vec3f(1,0,0),  // rotation on x
										 osg::DegreesToRadians(0.0f),osg::Vec3f(0,1,0),  // rotation on z
										 osg::DegreesToRadians(180.0f),osg::Vec3f(0,0,1) // rotation on y 
										 )
				   );

}


Sky::~Sky(){
    
}