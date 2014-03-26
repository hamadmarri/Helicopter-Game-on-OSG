//
//  Terrain.cpp
//
//	See main.cpp file header for credits
//
//	Terrain calls implementation has been created to call the model and set the model in some position in our scene.
//


#include "Terrain.h"


// constructor for the Terrain class 
Terrain::Terrain():Model() {
    
	// read the model from file and set the node's child
    this->node->addChild(osgDB::readNodeFile("lz.osg"));
	
	
	// set the posistion, rotation, scale
    this->matrixTransform->setMatrix(osg::Matrix::translate(0.0f, 0.0f, WORLD_GROUND)
                                     *  osg::Matrix::rotate(osg::DegreesToRadians(90.0f),osg::Vec3f(1,0,0),
                                                            osg::DegreesToRadians(0.0f),osg::Vec3f(0,1,0),
                                                            osg::DegreesToRadians(180.0f),osg::Vec3f(0,0,1)
                                                            )
                                     
                                     );
}


// desconstroctor 
Terrain::~Terrain(){
    
}