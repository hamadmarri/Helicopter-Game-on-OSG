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
}