//
//  Terrain.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#include "Terrain.h"
#include "Model.h"

// constructor for the Terrain class 
Terrain::Terrain():Model(){
    
    this->addChild(osgDB::readNodeFile("lz.osg"));
    this->matrixTransform->setMatrix(osg::Matrix::translate(0.0f, 300.0f, -400.0f)
                                     *  osg::Matrix::rotate(osg::DegreesToRadians(90.0f),osg::Vec3f(1,0,0),
                                                            osg::DegreesToRadians(0.0f),osg::Vec3f(0,1,0),
                                                            osg::DegreesToRadians(180.0f),osg::Vec3f(0,0,1)
                                                            )
                                     * osg::Matrix::scale(100, 100, 100)
                                     );
    

}