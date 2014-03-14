//
//  Terrain.cpp
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
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
                                     * osg::Matrix::scale(10, 10, 10)
                                     );
}
